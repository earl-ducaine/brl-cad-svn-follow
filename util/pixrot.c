/*
 *		P I X R O T . C
 *
 * Rotate, Invert, and/or Reverse the pixels in a RGB (.pix) file.
 *
 * The rotation logic was worked out for data ordered with
 *  "upper left" first.  It is being used on files in first
 *  quadrant order (lower left first).  Thus the "forward",
 *  "backward" flags are reversed.
 *
 * This is a generalization of bwrot and can in fact handle
 *  "pixels" of any size.  Thus this routine could be used
 *  to say, rotate a matix of floating point values, etc.
 *
 *  Author -
 *	Phillip Dykstra
 *	24 Sep 1986
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

unsigned char *malloc();

#define	MAXBUFBYTES	(1024*1024)

int	buflines, scanbytes;
int	firsty = -1;	/* first "y" scanline in buffer */
int	lasty = -1;	/* last "y" scanline in buffer */
unsigned char *buffer;
unsigned char *bp;
unsigned char *obuf;
unsigned char *obp;

int	xin, yin, xout, yout, nxin, nyin;
int	plus90, minus90, reverse, invert;
int	pixbytes = 3;

static	char *Usage = "usage: pixrot [-f -b -r -i -#bytes] nx ny < file.pix > file.pix\n";

FILE	*ifp, *ofp;

main( argc, argv )
int argc; char **argv;
{
	int	x, y, j;
	int	outbyte, outplace;

	/* Check for flags */
	while( argc > 1 && argv[1][0] == '-' )  {
		switch( argv[1][1] )  {
		case '#':
			pixbytes = atoi( &argv[1][2] );
			break;
		case 'f':
			minus90++;
			break;
		case 'b':
			plus90++;
			break;
		case 'r':
			reverse++;
			break;
		case 'i':
			invert++;
			break;
		default:
			fprintf( stderr, "pixrot: unrecognized flag '%s'\n", argv[1] );
			fprintf( stderr, Usage );
			exit( 1 );
		}
		argc--;
		argv++;
	}

	if( argc != 3 ) {
		fprintf( stderr, Usage );
		exit( 2 );
	}

	nxin = atoi( argv[1] );
	nyin = atoi( argv[2] );

	ifp = stdin;
	ofp = stdout;

	scanbytes = nxin * pixbytes;
	buflines = MAXBUFBYTES / scanbytes;
	if( buflines <= 0 ) {
		fprintf( stderr, "pixrot: I'm not compiled to do a scanline that long!\n" );
		exit( 1 );
	}
	if( buflines > nyin ) buflines = nyin;
	buffer = malloc( buflines * scanbytes );
	obuf = malloc( nyin * pixbytes );

	/*
	 * Clear our "file pointer."  We need to maintain this
	 * In order to tell if seeking is required.  ftell() always
	 * fails on pipes, so we can't use it.
	 */
	outplace = 0;

	yin = 0;
	while( yin < nyin ) {
		/* Fill buffer */
		fill_buffer();
		if( reverse )
			reverse_buffer();
		if( plus90 ) {
			for( x = 0; x < nxin; x++ ) {
				obp = obuf;
				bp = &buffer[ (lasty-firsty)*scanbytes + x*pixbytes ];
				for( y = lasty; y >= yin; y-- ) { /* firsty? */
					for( j = 0; j < pixbytes; j++ )
						*obp++ = *bp++;
					bp = bp - scanbytes - pixbytes;
				}
				yout = x;
				xout = (nyin - 1) - lasty;
				outbyte = ((yout * nyin) + xout) * pixbytes;
				if( outplace != outbyte ) {
					if( fseek( ofp, outbyte, 0L ) < 0 ) {
						fprintf( stderr, "pixrot: Can't seek on output, yet I need to!\n" );
						exit( 3 );
					}
					outplace = outbyte;
				}
				fwrite( obuf, pixbytes, buflines, ofp );
				outplace += (pixbytes * buflines);
			}
		} else if( minus90 ) {
			for( x = nxin-1; x >= 0; x-- ) {
				obp = obuf;
				bp = &buffer[ x*pixbytes ];
				for( y = firsty; y <= lasty; y++ ) {
					for( j = 0; j < pixbytes; j++ )
						*obp++ = *bp++;
					bp = bp + scanbytes - pixbytes;
				}
				yout = (nxin - 1) - x;
				xout = yin;
				outbyte = ((yout * nyin) + xout) * pixbytes;
				if( outplace != outbyte ) {
					if( fseek( ofp, outbyte, 0L ) < 0 ) {
						fprintf( stderr, "pixrot: Can't seek on output, yet I need to!\n" );
						exit( 3 );
					}
					outplace = outbyte;
				}
				fwrite( obuf, pixbytes, buflines, ofp );
				outplace += (pixbytes * buflines);
			}
		} else if( invert ) {
			for( y = lasty; y >= firsty; y-- ) {
				yout = (nyin - 1) - y;
				outbyte = yout * scanbytes; 
				if( outplace != outbyte ) {
					if( fseek( ofp, outbyte, 0L ) < 0 ) {
						fprintf( stderr, "pixrot: Can't seek on output, yet I need to!\n" );
						exit( 3 );
					}
					outplace = outbyte;
				}
				fwrite( &buffer[(y-firsty)*scanbytes], 1, scanbytes, ofp );
				outplace += scanbytes;
			}
		} else {
			/* Reverse only */
			for( y = 0; y < buflines; y++ ) {
				fwrite( &buffer[y*scanbytes], 1, scanbytes, ofp );
			}
		}

		yin += buflines;
	}
}

fill_buffer()
{
	firsty = lasty + 1;
	lasty = firsty + (buflines - 1);

	fread( buffer, 1, scanbytes * buflines, ifp );
}

reverse_buffer()
{
	int	i, j;
	unsigned char *p1, *p2, temp;

	for( i = 0; i < buflines; i++ ) {
		p1 = &buffer[ i * scanbytes ];
		p2 = p1 + (scanbytes - pixbytes);
		while( p1 < p2 ) {
			for( j = 0; j < pixbytes; j++ ) {
				temp = *p1;
				*p1++ = *p2;
				*p2++ = temp;
			}
			p2 -= 2*pixbytes;
		}
	}
}
