/*                     R T E X A M P L E . C
 * BRL-CAD
 *
 * Copyright (c) 2004-2008 United States Government as represented by
 * the U.S. Army Research Laboratory.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * version 2.1 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this file; see the file named COPYING for more
 * information.
 */
/** @file rtexample.c
 *
 * This is a heavily commented example of a program that uses librt to
 * shoot a single ray at some geometry in a .g database.
 *
 * The primary BRL-CAD ray-tracing API consists of calls to the
 * function rt_shootray().  This function takes a single argument, the
 * address of a data structure called the "application" structure.
 * This data structure contains crucial information, such as the
 * origin and direction of the ray to be traced, what to do if the ray
 * hits geometry, or what to do if it misses everything.  While the
 * application struct is a large and somewhat complex looking, (it is
 * defined in the raytrace.h header) there are really very few items
 * in it which the application programmer must know about. These are:
 *
 *   a_rt_i	The "raytrace instance" obtained via rt_dirbuild()
 *   a_ray	The ray origin and direction to be shot
 *   a_hit	A callback function for when the ray encounters geometry
 *   a_miss	A callback function for when the ray misses everything
 *
 * Most of the work an application performs will be done in the "hit"
 * routine.  This user-supplied routine gets called deep inside the
 * raytracing library via the rt_shootray() function.  It is provided
 * with 3 parameters:
 *
 *   ap		Pointer to the application structure passed to rt_shootray()
 *   PartHeadp	List of ray "partitions" which represent geometry hit
 *   segp	List of ray "segments" that comprised partitions
 *
 * Most applications can ignore the last parameter.  The PartHeadp
 * parameter is a linked-list of "partition" structures (defined in
 * the raytrace.h header).  It is the job of the "hit" routine to
 * process these ray/object intersections to do the work of the
 * application.
 *
 * This file is part of the default compile in source distributions of
 * BRL-CAD and is usually installed or provided via binary and source
 * distributions.  To compile this example from a binary install:
 *
 * cc -I/usr/brlcad/include/brlcad -L/usr/brlcad/lib -o rtexample rtexample.c -lbu -lrt -lm
 *
 */

#include "common.h"

#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "bio.h"

#include "vmath.h"		/* vector math macros */
#include "raytrace.h"		/* librt interface definitions */


/*
 * rt_shootray() was told to call this on a hit.  He gives up the
 * application structure which describes the state of the world (see
 * raytrace.h), and a circular linked list of partitions, each one
 * describing one in and out segment of one region.
 */
int
hit(register struct application *ap, struct partition *PartHeadp, struct seg *segs)
{
    /* see raytrace.h for all of these guys */
    register struct partition *pp;
    register struct hit *hitp;
    register struct soltab *stp;
    struct curvature cur;
    point_t		pt;
    vect_t		inormal;
    vect_t		onormal;

    /* examine each partition until we get back to the head */
    for (pp=PartHeadp->pt_forw; pp != PartHeadp; pp = pp->pt_forw) {
	bu_log("\n--- Hit region %s (in %s, out %s)\n",
	       pp->pt_regionp->reg_name,
	       pp->pt_inseg->seg_stp->st_name,
	       pp->pt_outseg->seg_stp->st_name );

	/* inhit info */
	hitp = pp->pt_inhit;
	stp = pp->pt_inseg->seg_stp;

	VJOIN1(pt, ap->a_ray.r_pt, hitp->hit_dist, ap->a_ray.r_dir);

	/* This macro takes care of the flip flag and all that */
	RT_HIT_NORMAL(inormal, hitp, stp, &(ap->a_ray), pp->pt_inflip);

	rt_pr_hit("  In", hitp);
	VPRINT(   "  Ipoint", pt);
	VPRINT(   "  Inormal", inormal);
	/*
	 * This next macro fills in the curvature information
	 * which consists on a principle direction vector, and
	 * the inverse radii of curvature along that direction
	 * and perpendicular to it.  Positive curvature bends
	 * toward the outward pointing normal.
	 */
	RT_CURVATURE(&cur, hitp, pp->pt_inflip, stp);
	VPRINT("PDir", cur.crv_pdir);
	bu_log(" c1=%g\n", cur.crv_c1);
	bu_log(" c2=%g\n", cur.crv_c2);

	/* outhit info */
	hitp = pp->pt_outhit;
	stp = pp->pt_outseg->seg_stp;
	VJOIN1(pt, ap->a_ray.r_pt, hitp->hit_dist, ap->a_ray.r_dir);
	RT_HIT_NORMAL(onormal, hitp, stp, &(ap->a_ray), pp->pt_outflip);

	rt_pr_hit("  Out", hitp);
	VPRINT(   "  Opoint", pt);
	VPRINT(   "  Onormal", onormal);
    }

    /*
     * A more complicated application would probably fill in a
     * new local application structure and describe say a reflected
     * or refracted ray, and then call rt_shootray with it.
     */

    /*
     * This value is returned by rt_shootray
     * a hit usually returns 1, miss 0.
     */
    return 1;
}


/*
 * rt_shootray() was told to call this on a miss.
 */
int
miss(register struct application *ap)
{
    bu_log("missed\n");
    return 0;
}


int
main(int argc, char **argv)
{
    /* Every application needs one of these.  The "application"
     * structure carries information about how the ray-casting should
     * be performed.  Defined in the raytrace.h header.
     */
    struct application	ap;

    /* The "raytrace instance" structure contains definitions for
     * librt which are specific to the particular model being
     * processed.  One copy exists for each model.  Defined in
     * the raytrace.h header and is returned by rt_dirbuild().
     */
    static struct rt_i *rtip;

    /* optional parameter to rt_dirbuild() what can be used to capture
     * a title if the geometry database has one set.
     */
    char title[1024] = {0};

    /* Check for command-line arguments.  Make sure we have at least a
     * geometry file and one geometry object on the command line.
     */
    if (argc < 3) {
	bu_exit(1, "Usage: %s model.g objects...\n", argv[0]);
    }

    /*
     *  Load database.
     *  rt_dirbuild() returns an "instance" pointer which describes
     *  the database to be ray traced.  It also gives you back the
     *  title string in the header (ID) record.
     */
    rtip = rt_dirbuild(argv[1], title, sizeof(title));
    if (rtip == RTI_NULL) {
	bu_exit(2, "%s: rt_dirbuild failure\n", argv[0]);
    }

    /* initialize all values in application structure to zero */
    RT_APPLICATION_INIT(&ap);

    /* your application uses this instance */
    ap.a_rt_i = rtip;
    fprintf(stderr, "Title:\n%s\n", title);

    /* Walk trees.  Here you identify any object trees in the database
     * that you want included in the ray trace.
     */
    while (argc > 2)  {
	if (rt_gettree(rtip, argv[2]) < 0)
	    fprintf(stderr, "rt_gettree(%s) FAILED\n", argv[0]);
	argc--;
	argv++;
    }

    /* This next call gets the database ready for ray tracing.  (it
     * precomputes some values, sets up space partitioning, etc.)
     */
    rt_prep_parallel(rtip, 1);

    /* Set the ray start point and direction rt_shootray() uses these
     * two to determine what ray to fire.  In this case we simply
     * shoot down the z axis toward the origin from 10 meters away
     * [librt assumes units of millimeters.  not that is really maters
     * here, but an MGED database made with units=mm will have the
     * same values in the file (and thus in librt) that you see
     * displayed by MGED.
     */
    VSET(ap.a_ray.r_pt, 0, 0, 10000);
    VSET(ap.a_ray.r_dir, 0, 0, -1);

    VPRINT("Pnt", ap.a_ray.r_pt);
    VPRINT("Dir", ap.a_ray.r_dir);

    /* Shoot Ray */
    ap.a_hit = hit;		/* where to go on a hit */
    ap.a_miss = miss;		/* where to go on a miss */
    (void)rt_shootray(&ap);	/* do it */

    /*
     * A real application would probably set up another ray and fire
     * again or do something a lot more complex in the callbacks.
     */

    return 0;
}


/*
 * Local Variables:
 * mode: C
 * tab-width: 8
 * indent-tabs-mode: t
 * c-file-style: "stroustrup"
 * End:
 * ex: shiftwidth=4 tabstop=8
 */
