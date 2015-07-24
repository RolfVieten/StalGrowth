////////////////////////////////////////////////////////////////////////////////
#include <math.h>      // required for powl(), sinl(), fabsl() and ldexpl().
#include <float.h>     // required for DBL_MAX and LDBL_MAX
#include <limits.h>    // required for LONG_MAX

double Gamma_Function(double x);
long double xGamma_Function(long double x);
double Gamma_Function_Max_Arg( void );
long double xGamma_Function_Max_Arg( void );

static long double xGamma(long double x);
static long double Duplication_Formula( long double two_x );

double Ln_Gamma_Function(double x);
long double xLn_Gamma_Function(long double x);
static long double xLnGamma_Asymptotic_Expansion( long double x );

double Beta_Function(double a, double b);
long double xBeta_Function(long double a, long double b);

double Ln_Beta_Function(double a, double b);
long double xLn_Beta_Function(long double a, long double b);

static long double Beta_Continued_Fraction( long double x, long double a, long double b);
static long double xBeta_Distribution(double x, double a, double b);

double Beta_Distribution(double x, double a, double b);

double Student_t_Distribution(double x, int n);
double Student_t_Density( double x, int n );

static long double const e =  2.71828182845904523536028747L;
static long double const pi = 3.14159265358979323846264338L;
static long double const g =  9.65657815377331589457187L;
static long double const exp_g_o_sqrt_2pi = +6.23316569877722552586386e+3L;
static double max_double_arg = 171.0;
static long double max_long_double_arg = 1755.5L;
static const long double ln_LDBL_MAX =  1.13565234062941435e+4L;

static long double const a[] = {
                                 +1.14400529453851095667309e+4L,
                                 -3.23988020152318335053598e+4L,
                                 +3.50514523505571666566083e+4L,
                                 -1.81641309541260702610647e+4L,
                                 +4.63232990536666818409138e+3L,
                                 -5.36976777703356780555748e+2L,
                                 +2.28754473395181007645155e+1L,
                                 -2.17925748738865115560082e-1L,
                                 +1.08314836272589368860689e-4L
                              };


