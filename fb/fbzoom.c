/*
 *			F B Z O O M . C
 *
 * Function -
 *	Dynamicly modify Ikonas Zoom and Window parameters,
 *	using VI and/or EMACS-like keystrokes on a regular terminal.
 *
 *  Authors -
 *	Bob Suckling
 *	Michael John Muuss
 *	Gary S. Moss
 *
 *  Source -
 *	SECAD/VLD Computing Consortium, Bldg 394
 *	The U. S. Army Ballistic Research Laboratory
 *	Aberdeen Proving Ground, Maryland  21005-5066
 *  
 *  Copyright Notice -
 *	This software is Copyright (C) 1986 by the United States Army.
 *	All rights reserved.
 */
#ifndef lint
static char RCSid[] = "@(#)$Header$ (BRL)";
#endif

#include <stdio.h>	
#include "fb.h"

/* Zoom rate and limits.	*/
#define MaxZoom		(16)
#define MinZoom		(1)

/* Pan limits.	*/
#define MaxPan		fb_getwidth(fbp)
#define MinPan		(0)

static int PanFactor;			/* Speed with whitch to pan.	*/
static int zoom;			/* Zoom Factor.			*/
static int xPan, yPan;			/* Pan Location.		*/

static int fbsize = 512;
FBIO *fbp;

main(argc, argv )
char **argv;
	{
	if( ! pars_Argv( argc, argv ) )
		{
		(void) fprintf( stderr, "Usage : fbzoom	[-h]\n" );
		return	1;
		}
	if( (fbp = fb_open( NULL, fbsize, fbsize )) == NULL )
		return	1;
	zoom = 1;
	xPan = fb_getwidth(fbp)/2;
	yPan = fb_getheight(fbp)/2 - 1;

	/* Set RAW mode */
	save_Tty( 0 );
	set_Raw( 0 );
	clr_Echo( 0 );

	do
		{
		PanFactor = 40 / zoom;
		(void) fb_zoom( fbp, zoom, zoom );
		fb_window( fbp, xPan, yPan );
		(void) fprintf( stdout,
				"zoom=%d, Center Pixel is %d,%d            \r",
				zoom, xPan, yPan
				);
		(void) fflush( stdout );
		}
	while( doKeyPad() );

	reset_Tty( 0 );
	(void) fprintf( stdout,  "\n");	/* Move off of the output line.	*/
	(void) fb_zoom( fbp, zoom, zoom );
	(void) fb_window( fbp, xPan, yPan );
	(void) fb_close( fbp );
	return	0;
	}

char help[] = "\r\n\
b ^V	zoom Bigger\r\n\
s	zoom Smaller\r\n\
h	move Right\r\n\
j	move Up\r\n\
k	move Down\r\n\
l	move Left\r\n\
c	goto Center\r\n\
r	Reset to normal\r\n\
^F ^B	Forward, Back\r\n\
^N ^P	Down, Up\r\n\
\\n	Exit\r\n\
Uppercase takes big steps.\r\n";

#define ctl(x)	('x'&037)

doKeyPad()
	{ 
	register ch;	

	if( (ch = getchar()) == EOF )
		return	0;		/* done */

	switch( ch )
		{
	default :
		(void) fprintf( stdout,
				"\r\n'%c' bad -- Type ? for help\r\n",
				ch
				);
	case '?' :
		(void) fprintf( stdout, "\r\n%s", help );
		break;
	case '\r' :    
	case '\n' :				/* Done, return to normal */
	case 'q' :
		return	0;
	case 'Q' :				/* Done, leave "as is" */
		return	0;
	case 'c' :	
	case 'C' :				/* Center */
		xPan = yPan = 0;
		break;
	case 'r' :	
	case 'R' :				/* Reset */
		zoom = 1;
		xPan = fb_getwidth(fbp)/2;
		yPan = fb_getheight(fbp)/2 - 1;
		break;
	case ctl(v) :
	case 'b' :				/* zoom BIG.	*/
		if(  (zoom *= 2) > MaxZoom )
			zoom = MaxZoom;
		break;
	case 's' :				/* zoom small.	*/
		if(  (zoom /= 2) < MinZoom )
			zoom = MinZoom;
		break;
	case 'F' :
	case 'l' :				/* move LEFT.	*/
		if( ++xPan > MaxPan )
			xPan = MaxPan;
		break;
	case ctl(f) :
	case 'L' :
		if( (xPan += PanFactor) > MaxPan )
			xPan = MaxPan;
		break;
	case 'N' :
	case 'k' :				/* move DOWN.	*/
		if( ++yPan > MaxPan )
			yPan = MaxPan;
		break;
	case ctl(n) :
	case 'K' :
		if( (yPan += PanFactor) > MaxPan )
			yPan = MaxPan;
		break;
	case 'P' :
	case 'j' :				/* move UP.	*/
		if( --yPan < MinPan )
			yPan = MinPan;
		break;
	case ctl(p) :
	case 'J' :
		if( (yPan -= PanFactor) < MinPan )
			yPan = MinPan;
		break;
	case 'B' :
	case 'h' :				/* move RIGHT.	*/
		if( --xPan < MinPan )
			xPan = MinPan;
		break;
	case ctl(b) :
	case 'H' :
		if( (xPan -= PanFactor) < MinPan )
			xPan = MinPan;
		break;
		}
	return	1;		/* keep going */
	}

/*	p a r s _ A r g v ( )
 */
int
pars_Argv( argc, argv )
register char	**argv;
	{
	register int	c;
	while( (c = getopt( argc, argv, "h" )) != EOF )
		{
		switch( c )
			{
			case 'h' : /* High resolution frame buffer.	*/
				fbsize = 1024;
				break;
			case '?' :
				return	0;
			}
		}
	return	1;
	}

