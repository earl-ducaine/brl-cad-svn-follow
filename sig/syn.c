/*
 *  Multi Sine Synthesis
 */
#include <stdio.h>
#include <math.h>
#include "./complex.h"

#define TABSIZE	512
double	sintab[TABSIZE];

static char usage[] = "\
Usage: syn samples_per_set [ratio] > doubles\n";

main( argc, argv )
int	argc;
char	**argv;
{
	int	i;
	double	d;
	double	period, stepsize, findex;
	int	setsize;

	if( isatty(fileno(stdout)) || argc < 2 ) {
		fprintf( stderr, usage );
		exit( 1 );
	}

	makesintab();
	fprintf(stderr, "init done\n");

	setsize = atoi(argv[1]);

	findex = 0;
	stepsize = 0;
	while( fread(&period, sizeof(period), 1, stdin) == 1 ) {
		if( period > 0 )
			stepsize = TABSIZE / period;
		for( i = setsize; i > 0; i-- ) {
			d = sintab[(int)findex];
			d *= 0.4;
			fwrite( &d, sizeof(d), 1, stdout );
			findex += stepsize;
			if( findex > TABSIZE )
				findex -= TABSIZE;
		}
	}
}

makesintab()
{
	int	i;
	double	theta;

	for( i = 0; i < TABSIZE; i ++ ) {
		theta = i / (double)TABSIZE * TWOPI;
		sintab[i] = sin(theta);
	}
}
