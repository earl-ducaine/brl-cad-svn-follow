/*
 *	---->	u p 2 h p g l   <----
 *
 * Description -
 *	Convert a unix-plot file to hpgl codes.
 *
 * Author -  
 *	Mark Huston Bowden  
 *	Research Institute, E-47 
 *	University of Alabama in Huntsville  
 *	Huntsville, AL  35899
 *	(205) 895-6467 UAH
 *	(205) 876-1089 Redstone Arsenal
 */

#include <stdio.h>

#define ASPECT	(9.8/7.1)
#define	geti(x)	{ (x) = getchar(); (x) |= (short)(getchar()<<8); }
#define getb(x)	((x) = getchar())

main(argc,argv)
int argc;
char **argv;
{
    char colors[8][3],s[1024];
    int numcolors,c,i,x,y,x1,x2,y1,y2,r,g,b;

    if (argc != 1) {
	printf("Usage: %s < infile > outfile\n",argv[0]);
	exit(1);
    }

    getb(c);
    do {
	switch (c) {
	    case 'p':		/* point */
		geti(x);
		geti(y);
		printf("PU;\n");
		printf("PA %d %d;\n",x,y);
		printf("PD;\n");
		break;
	    case 'l':		/* line */
		geti(x1);
		geti(y1);
		geti(x2);
		geti(y2);
		printf("PU;\n");
		printf("PA %d %d;\n",x1,y1);
		printf("PD;\n");
		printf("PA %d %d;\n",x2,y2);
		break;
	    case 'f':		/* line style */
		for (i = 0; (s[i] = getchar()) != '\n'; i++);
		s[i] = '\0';
		/* set line style */
		break;
	    case 'm':		/* move */
		geti(x);
		geti(y);
		printf("PU;\n");
		printf("PA %d %d;\n",x,y);
		break;
	    case 'n':		/* draw */
		geti(x);
		geti(y);
		printf("PD;\n");
		printf("PA %d %d;\n",x,y);
		break;
	    case 't':		/* text */
		for (i = 0; (s[i] = getchar()) != '\n'; i++);
		s[i] = '\0';
		/* draw text */
		break;
	    case 's':		/* space */
		geti(x1);
		geti(y1);
		geti(x2);
		geti(y2);
		x1 *= ASPECT;
		x2 *= ASPECT;
		printf("SC %d %d %d %d;\n",x1,x2,y1,y2);
		printf("SP 1;\n");
		printf("PU;\n");
		printf("PA %d %d;\n",x1,y1);
		printf("PD;\n");
		printf("PA %d %d;\n",x1,y2);
		printf("PA %d %d;\n",x2,y2);
		printf("PA %d %d;\n",x2,y1);
		printf("PA %d %d;\n",x1,y1);
		break;
	    case 'C':		/* color */
		r = getchar();
		g = getchar();
		b = getchar();
		for (i = 0; i < numcolors; i++)
		    if (r == colors[i][0] 
		    &&  g == colors[i][1] 
		    &&  b == colors[i][2])
			break;
		if (i < numcolors)
		    i++;
		else
		    if (numcolors < 8) {
			colors[numcolors][0] = r;
			colors[numcolors][1] = g;
			colors[numcolors][2] = b;
			numcolors++;
			i++;
		    } else
			i = 8;
		printf("SP %d;\n",i);
		break;
	    default:
		break;
	}
	getb(c);
    } while (!feof(stdin));
}
