/*
 *			I F _ N U L L . C
 *
 *  A Null Frame Buffer.
 *  Useful for benchmarking or debugging.
 *
 *  Authors -
 *	Phillip Dykstra
 *
 *  Source -
 *	SECAD/VLD Computing Consortium, Bldg 394
 *	The U. S. Army Ballistic Research Laboratory
 *	Aberdeen Proving Ground, Maryland  21005-5066
 *  
 *  Copyright Notice -
 *	This software is Copyright (C) 1989 by the United States Army.
 *	All rights reserved.
 */
#ifndef lint
static char RCSid[] = "@(#)$Header$ (BRL)";
#endif

#include "fb.h"
#include "./fblocal.h"

_LOCAL_ int	null_open(),
		null_close(),
		null_reset(),
		null_clear(),
		null_read(),
		null_write(),
		null_rmap(),
		null_wmap(),
		null_viewport(),
		null_window(),
		null_zoom(),
		null_setcursor(),
		null_cursor(),
		null_scursor(),
		null_readrect(),
		null_writerect(),
		null_flush(),
		null_free(),
		null_help();

/* This is the ONLY thing that we normally "export" */
FBIO null_interface =  {
	null_open,		/* device_open		*/
	null_close,		/* device_close		*/
	null_reset,		/* device_reset		*/
	null_clear,		/* device_clear		*/
	null_read,		/* buffer_read		*/
	null_write,		/* buffer_write		*/
	null_rmap,		/* colormap_read	*/
	null_wmap,		/* colormap_write	*/
	null_viewport,		/* viewport_set		*/
	null_window,		/* window_set		*/
	null_zoom,		/* zoom_set		*/
	null_setcursor,		/* curs_set		*/
	null_cursor,		/* cursor_move_memory_addr */
	null_scursor,		/* cursor_move_screen_addr */
	null_readrect,		/* rectangle read	*/
	null_writerect,		/* rectangle write	*/
	null_flush,		/* flush output		*/
	null_free,		/* free resources	*/
	null_help,		/* help message		*/
	"Null Device",		/* device description	*/
	32*1024,		/* max width		*/
	32*1024,		/* max height		*/
	"/dev/null",		/* short device name	*/
	512,			/* default/current width  */
	512,			/* default/current height */
	-1,			/* file descriptor	*/
	PIXEL_NULL,		/* page_base		*/
	PIXEL_NULL,		/* page_curp		*/
	PIXEL_NULL,		/* page_endp		*/
	-1,			/* page_no		*/
	0,			/* page_dirty		*/
	0L,			/* page_curpos		*/
	0L,			/* page_pixels		*/
	0			/* debug		*/
};

_LOCAL_ int
null_open( ifp, file, width, height )
FBIO	*ifp;
char	*file;
int	width, height;
{
	if( width > 0 )
		ifp->if_width = width;
	if( height > 0 )
		ifp->if_height = height;

	return(0);
}

_LOCAL_ int
null_close( ifp )
FBIO	*ifp;
{
	return(0);
}

_LOCAL_ int
null_reset( ifp )
FBIO	*ifp;
{
	return(0);
}

_LOCAL_ int
null_clear( ifp, pp )
FBIO	*ifp;
RGBpixel	*pp;
{
	return(0);
}

_LOCAL_ int
null_read( ifp, x, y, pixelp, count )
FBIO	*ifp;
int	x, y;
RGBpixel	*pixelp;
int	count;
{
	return(count);
}

_LOCAL_ int
null_write( ifp, x, y, pixelp, count )
FBIO	*ifp;
int	x, y;
RGBpixel	*pixelp;
int	count;
{
	return(count);
}

_LOCAL_ int
null_rmap( ifp, cmp )
FBIO	*ifp;
ColorMap	*cmp;
{
	return(0);
}

_LOCAL_ int
null_wmap( ifp, cmp )
FBIO	*ifp;
ColorMap	*cmp;
{
	return(0);
}

_LOCAL_ int
null_viewport( ifp, left, top, right, bottom )
FBIO	*ifp;
int	left, top, right, bottom;
{
	return(0);
}

_LOCAL_ int
null_window( ifp, x, y )
FBIO	*ifp;
int	x, y;
{
	return(0);
}

_LOCAL_ int
null_zoom( ifp, x, y )
FBIO	*ifp;
int	x, y;
{
	return(0);
}

_LOCAL_ int
null_setcursor( ifp, bits, xbits, ybits, xorig, yorig )
FBIO	*ifp;
unsigned char *bits;
int	xbits, ybits;
int	xorig, yorig;
{
	return(0);
}

_LOCAL_ int
null_cursor( ifp, mode, x, y )
FBIO	*ifp;
int	mode;
int	x, y;
{
	return(0);
}

_LOCAL_ int
null_scursor( ifp, mode, x, y )
FBIO	*ifp;
int	mode;
int	x, y;
{
	return(0);
}

_LOCAL_ int
null_readrect( ifp, xmin, ymin, width, height, pp )
FBIO	*ifp;
int	xmin, ymin;
int	width, height;
RGBpixel	*pp;
{
	return( width*height );
}

_LOCAL_ int
null_writerect( ifp, xmin, ymin, width, height, pp )
FBIO	*ifp;
int	xmin, ymin;
int	width, height;
RGBpixel	*pp;
{
	return( width*height );
}

_LOCAL_ int
null_flush( ifp )
FBIO	*ifp;
{
	return(0);
}

_LOCAL_ int
null_free( ifp )
FBIO	*ifp;
{
	return(0);
}

_LOCAL_ int
null_help( ifp )
FBIO	*ifp;
{
	fb_log( "Description: %s\n", null_interface.if_type );
	fb_log( "Device: %s\n", ifp->if_name );
	fb_log( "Max width/height: %d %d\n",
		null_interface.if_max_width,
		null_interface.if_max_height );
	fb_log( "Default width/height: %d %d\n",
		null_interface.if_width,
		null_interface.if_height );
	fb_log( "Useful for Benchmarking/Debugging\n" );
	return(0);
}
