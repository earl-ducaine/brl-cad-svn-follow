/*		U S R F M T . H
*/

#define			OUTITEM_NULL		((outitem *) 0)
#define			OVERLAP_NULL		((overlap *) 0)
#define			DEF_RCF_NAME		".nirtrc"
#define			DEF_SF_NAME		"nirt_state"
#define			CMT_CHAR		'#'

typedef struct outitem_tag
{
    char		*format;
    int			code_nm;
    struct outitem_tag	*next;
} 					outitem;

typedef struct
{
    char		*name;
    int			code_nm;
    int			type;
    union ovv {
	fastf_t	fval;
	char	*sval;
	int	ival;
	}		value;
}					outval;

typedef struct ovlp_tag
{
    struct application	*ap;
    struct partition	*pp;
    struct region	*reg1;
    struct region	*reg2;
    fastf_t		in_dist;
    fastf_t		out_dist;
    point_t		in_point;
    point_t		out_point;
    struct ovlp_tag	*forw;
    struct ovlp_tag	*backw;
}					overlap;

extern FILE	*fopenrc();

/* Codes for output-item data types */
#define		OIT_INT		0
#define		OIT_FLOAT	1
#define		OIT_FNOUNIT	2	/* Local units don't apply */
#define		OIT_STRING	3
#define		oit_name(t)	(((t)==OIT_INT) ? "int" :\
				 ((t)==OIT_FLOAT) ? "float" :\
				 ((t)==OIT_FNOUNIT) ? "float" :\
				 ((t)==OIT_STRING) ? "string" : "unknown")

/* Codes for output-statement types */
#define		FMT_RAY 	0
#define		FMT_HEAD	1	/* Don't change this w/o */
#define		FMT_PART	2	/* changing fmt_char[]	 */
#define		FMT_FOOT	3	/* in dump_state()	 */
#define		FMT_MISS	4
#define		FMT_OVLP	5
#define		FMT_NONE	6

/* Indices into the table of output values
 *
 *	WARNING - Don't change these #defines without
 *			changing the initialization of
 *			ValTab[]!
 */
#define		VTI_LITERAL	0
#define		VTI_X_ORIG	1
#define		VTI_Y_ORIG	2
#define		VTI_Z_ORIG	3
#define		VTI_H		4
#define		VTI_V		5
#define		VTI_D_ORIG	6
#define		VTI_X_DIR	7
#define		VTI_Y_DIR	8
#define		VTI_Z_DIR	9
#define		VTI_A		10
#define		VTI_E		11
#define		VTI_X_IN	12
#define		VTI_Y_IN	13
#define		VTI_Z_IN	14
#define		VTI_D_IN	15
#define		VTI_X_OUT	16
#define		VTI_Y_OUT	17
#define		VTI_Z_OUT	18
#define		VTI_D_OUT	19
#define		VTI_LOS		20
#define		VTI_PATH_NAME	21
#define		VTI_REG_NAME	22
#define		VTI_REG_ID	23
#define		VTI_OBLIQ_IN	24
#define		VTI_OBLIQ_OUT	25
#define		VTI_OV_REG1_NAME 26
#define		VTI_OV_REG1_ID	27
#define		VTI_OV_REG2_NAME 28
#define		VTI_OV_REG2_ID	29
#define		VTI_OV_SOL_IN	30
#define		VTI_OV_SOL_OUT	31
#define		VTI_OV_LOS	32
#define		VTI_OV_X_IN	33
#define		VTI_OV_Y_IN	34
#define		VTI_OV_Z_IN	35
#define		VTI_OV_D_IN	36
#define		VTI_OV_X_OUT	37
#define		VTI_OV_Y_OUT	38
#define		VTI_OV_Z_OUT	39
#define		VTI_OV_D_OUT	40

#define		direct(i)	(ValTab[VTI_X_DIR + i].value.fval)
#define		target(i)	(ValTab[VTI_X_ORIG + i].value.fval)
#define		r_entry(i)	(ValTab[VTI_X_IN + i].value.fval)
#define		r_exit(i)	(ValTab[VTI_X_OUT + i].value.fval)
#define		ov_entry(i)	(ValTab[VTI_OV_X_IN + i].value.fval)
#define		ov_exit(i)	(ValTab[VTI_OV_X_OUT + i].value.fval)
#define		grid(i)		(ValTab[VTI_H + i].value.fval)
#define		azimuth()	(ValTab[VTI_A].value.fval)
#define		elevation()	(ValTab[VTI_E].value.fval)

#define		D		3
