#include "matlib.h"
////////////////////////////////////////////////////////////////////////////////
// double Ln_Gamma_Function( double x )                                       //
//                                                                            //
//  Description:                                                              //
//     This function calculates the natural log of Gamma(x) for positive real //
//     x.                                                                     //
//     Assuming that Gamma_Function_Max_Arg() = 171, then                     //
//     If 0 < x <= 171, then ln(gamma(x)) is calculated by taking the natural //
//     log of the result from Gamma_Function(x).  If x > 171, then            //
//     ln(gamma(x)) is calculated using the asymptotic expansion              //
//         ln(gamma(x)) ~ ln(2sqrt(2pi)) - x + (x - 1/2) ln x +               //
//                        Sum B[2j] / [ 2j * (2j-1) * x^(2j-1) ], summed over //
//     j from 1 to 3 and where B[2j] is the 2j-th Bernoulli number.           //
//                                                                            //
//  Arguments:                                                                //
//     double x   Argument of the ln Gamma function. The argument x must be   //
//                positive.                                                   //
//                                                                            //
//  Return Values:                                                            //
//     ln(Gamma(x)) where x > 0.                                              //
//                                                                            //
//  Example:                                                                  //
//     double x, g;                                                           //
//                                                                            //
//     g = Ln_Gamma_Function( x );                                            //
////////////////////////////////////////////////////////////////////////////////

double Ln_Gamma_Function(double x)
{

       // For a positive argument, 0 < x <= Gamma_Function_Max_Arg() //
       // then  return log Gamma(x).                                 //

   if (x <= Gamma_Function_Max_Arg()) return log(Gamma_Function(x));

    // otherwise return result from asymptotic expansion of ln Gamma(x). //

   return (double) xLnGamma_Asymptotic_Expansion( (long double) x );
}


////////////////////////////////////////////////////////////////////////////////
// long double xLn_Gamma_Function( long double x )                            //
//                                                                            //
//  Description:                                                              //
//     This function calculates the natural log of Gamma(x) for positive real //
//     x.                                                                     //
//     Assuming that Gamma_Function_Max_Arg() = 171, then                     //
//     If 0 < x <= 171, then ln(gamma(x)) is calculated by taking the natural //
//     log of the result from Gamma_Function(x).  If x > 171, then            //
//     ln(gamma(x)) is calculated using the asymptotic expansion              //
//         ln(gamma(x)) ~ ln(2sqrt(2pi)) - x + (x - 1/2) ln x +               //
//                        Sum B[2j] / [ 2j * (2j-1) * x^(2j-1) ], summed over //
//     j from 1 to 3 and where B[2j] is the 2j-th Bernoulli number.           //
//                                                                            //
//  Arguments:                                                                //
//     long double x   Argument of the ln Gamma function. The argument x must //
//                     be positive.                                           //
//                                                                            //
//  Return Values:                                                            //
//     ln(Gamma(x)) where x > 0.                                              //
//                                                                            //
//  Example:                                                                  //
//     double x;                                                              //
//     long double g;                                                         //
//                                                                            //
//     g = xLn_Gamma_Function( x );                                           //
////////////////////////////////////////////////////////////////////////////////
long double xLn_Gamma_Function(long double x)
{

       // For a positive argument, 0 < x <= Gamma_Function_Max_Arg() //
       // then  return log Gamma(x).                                 //

   if (x <= Gamma_Function_Max_Arg()) return logl(xGamma_Function(x));

    // otherwise return result from asymptotic expansion of ln Gamma(x). //

   return xLnGamma_Asymptotic_Expansion( x );
}


////////////////////////////////////////////////////////////////////////////////
// static long double xLnGamma_Asymptotic_Expansion( long double x )          //
//                                                                            //
//  Description:                                                              //
//     This function estimates log(gamma(x)) by evaluating the asymptotic     //
//     expression:                                                            //
//         ln(Gamma(x)) ~ ln(2sqrt(2pi)) - x + (x - 1/2) ln x +               //
//                        Sum B[2j] / [ 2j * (2j-1) * x^(2j-1) ], summed over //
//     j from 1 to 3 and where B[2j] is the 2j-th Bernoulli number.           //
//                                                                            //
//  Arguments:                                                                //
//     long double x   Argument of the ln Gamma function. The argument x must //
//                     be  positive.                                          //
//                                                                            //
//  Return Values:                                                            //
//     ln(Gamma(x)) where x > Gamma_Function_Max_Arg()                        //
//                                                                            //
//  Example:                                                                  //
//     double x;                                                              //
//     long double g;                                                         //
//                                                                            //
//     g = xlnGamma_Asymptotic_Expansion( x );                                //
////////////////////////////////////////////////////////////////////////////////

static const long double log_sqrt_2pi = 9.18938533204672741780329736e-1L;

// Bernoulli numbers B(2),B(4),B(6),...,B(20).  Only B(2),...,B(6) currently //
// used.                                                                     //

static const long double B[] = {   1.0L / (long double)(6 * 2 * 1),
                                  -1.0L / (long double)(30 * 4 * 3),
                                   1.0L / (long double)(42 * 6 * 5),
                                  -1.0L / (long double)(30 * 8 * 7),
                                   5.0L / (long double)(66 * 10 * 9),
                                -691.0L / (long double)(2730 * 12 * 11),
                                   7.0L / (long double)(6 * 14 * 13),
                               -3617.0L / (long double)(510 * 16 * 15),
                               43867.0L / (long double)(796 * 18 * 17),
                             -174611.0L / (long double)(330 * 20 * 19) 
                           };

static const int n = sizeof(B) / sizeof(long double);

static long double xLnGamma_Asymptotic_Expansion( long double x ) {
   const int  m = 3;
   long double term[3];
   long double sum = 0.0L;
   long double xx = x * x;
   long double xj = x;
   long double lngamma = log_sqrt_2pi - xj + (xj - 0.5L) * logl(xj);
   int i;

   for (i = 0; i < m; i++) { term[i] = B[i] / xj; xj *= xx; }
   for (i = m - 1; i >= 0; i--) sum += term[i]; 
   return lngamma + sum;
}

////////////////////////////////////////////////////////////////////////////////
// double Gamma_Function( double x )                                          //
//                                                                            //
//  Description:                                                              //
//     This function uses Lanczos' expression to calculate Gamma(x) for real  //
//     x, where -(max_double_arg - 1) < x < max_double_arg.                   //
//     Note the Gamma function is meromorphic in the complex plane and has    //
//     poles at the nonpositive integers.                                     //
//     Tests for x a positive integer or a half positive integer give a       //
//     maximum absolute relative error of about 1.9e-16.                      //
//                                                                            //
//     If x > max_double_arg, then one should either use xGamma_Function(x)   //
//     or calculate lnGamma(x).                                               //
//     Note that for x < 0, ln (Gamma(x)) may be a complex number.            //
//                                                                            //
//  Arguments:                                                                //
//     double x   Argument of the Gamma function.                             //
//                                                                            //
//  Return Values:                                                            //
//     If x is positive and is less than max_double_arg then Gamma(x) is      //
//     returned and if x > max_double_arg then DBL_MAX is returned.  If x is  //
//     a nonpositive integer i.e. x is a pole, then DBL_MAX is returned       //
//     ( note that Gamma(x) changes sign on each side of the pole).  If x is  //
//     nonpositive nonintegral, then if Gamma(x) > DBL_MAX, then DBL_MAX is   //
//     returned and if Gamma(x) < -DBL_MAX, then -DBL_MAX is returned.        //
//                                                                            //
//  Example:                                                                  //
//     double x, g;                                                           //
//                                                                            //
//     g = Gamma_Function( x );                                               //
////////////////////////////////////////////////////////////////////////////////
double Gamma_Function(double x)
{
   long double g;

   if ( x > max_double_arg ) return DBL_MAX;
   g = xGamma_Function( (long double) x);
   if (fabsl(g) < DBL_MAX) return (double) g;
   return (g < 0.0L) ? -DBL_MAX : DBL_MAX;

}


////////////////////////////////////////////////////////////////////////////////
// long double xGamma_Function( long double x )                               //
//                                                                            //
//  Description:                                                              //
//     This function uses Lanczos' expression to calculate Gamma(x) for real  //
//     x, where -(max_long_double_arg - 1) < x < max_long_double_arg.         //
//     Note the Gamma function is meromorphic in the complex plane and has    //
//     poles at the nonpositive integers.                                     //
//     Tests for x a positive integer or a half positive integer give a       //
//     maximum absolute relative error of about 3.5e-16.                      //
//                                                                            //
//     If x > max_long_double_arg, then one should use lnGamma(x).            //
//     Note that for x < 0, ln (Gamma(x)) may be a complex number.            //
//                                                                            //
//  Arguments:                                                                //
//     long double x   Argument of the Gamma function.                        //
//                                                                            //
//  Return Values:                                                            //
//     If x is positive and is less than max_long_double_arg, then Gamma(x)   //
//     is returned and if x > max_long_double_arg, then LDBL_MAX is returned. //
//     If x is a nonpositive integer i.e. x is a pole, then LDBL_MAX is       //
//     returned ( note that Gamma(x) changes sign on each side of the pole).  //
//     If x is nonpositive nonintegral, then if x > -(max_long_double_arg + 1)//
//     then Gamma(x) is returned otherwise 0.0 is returned.                   //
//                                                                            //
//  Example:                                                                  //
//     long double x, g;                                                      //
//                                                                            //
//     g = xGamma_Function( x );                                              //
////////////////////////////////////////////////////////////////////////////////
long double xGamma_Function(long double x)
{
   long double sin_x;
   long double rg;
   long int ix;

             // For a positive argument (x > 0)                 //
             //    if x <= max_long_double_arg return Gamma(x)  //
             //    otherwise      return LDBL_MAX.              //

   if ( x > 0.0L )
      if (x <= max_long_double_arg) return xGamma(x);
      else return LDBL_MAX;

                   // For a nonpositive argument (x <= 0) //
                   //    if x is a pole return LDBL_MAX   //

   if ( x > -(long double)LONG_MAX) {
      ix = (long int) x;
      if ( x == (long double) ix) return LDBL_MAX;
   }
   sin_x = sinl(pi * x);
   if ( sin_x == 0.0L ) return LDBL_MAX;

          // if x is not a pole and x < -(max_long_double_arg - 1) //
          //                                     then return 0.0L  //

   if ( x < -(max_long_double_arg - 1.0L) ) return 0.0L;

            // if x is not a pole and x >= -(max_long_double - 1) //
            //                               then return Gamma(x) //

   rg = xGamma(1.0L - x) * sin_x / pi;
   if ( rg != 0.0L ) return (1.0L / rg);
   return LDBL_MAX;
}


////////////////////////////////////////////////////////////////////////////////
// static long double xGamma( long double x )                                 //
//                                                                            //
//  Description:                                                              //
//     This function uses Lanczos' expression to calculate Gamma(x) for real  //
//     x, where 0 < x <= 900. For 900 < x < 1755.5, the duplication formula   //
//     is used.                                                               //
//     The major source of relative error is in the use of the c library      //
//     function powl().  The results have a relative error of about 10^-16.   //
//     except near x = 0.                                                     //
//                                                                            //
//     If x > 1755.5, then one should calculate lnGamma(x).                   //
//                                                                            //
//  Arguments:                                                                //
//     long double x   Argument of the Gamma function.                        //
//                                                                            //
//  Return Values:                                                            //
//     If x is positive and is less than 1755.5 then Gamma(x) is returned and //
//     if x > 1755.5 then LDBL_MAX is returned.                               //
//                                                                            //
//  Example:                                                                  //
//     long double x;                                                         //
//     long double g;                                                         //
//                                                                            //
//     g = xGamma_Function( x );                                              //
////////////////////////////////////////////////////////////////////////////////
static long double xGamma(long double x)
{

   long double xx = (x < 1.0L) ? x + 1.0L : x;
   long double temp;
   int const n = sizeof(a) / sizeof(long double);
   int i;

   if (x > 1755.5L) return LDBL_MAX;

   if (x > 900.0L) return Duplication_Formula(x);

   temp = 0.0L;
   for (i = n-1; i >= 0; i--) {
      temp += ( a[i] / (xx + (long double) i) );
   }
   temp += 1.0L;
   temp *= ( powl((g + xx - 0.5L) / e, xx - 0.5L) / exp_g_o_sqrt_2pi );
   return (x < 1.0L) ?  temp / x : temp;
}


////////////////////////////////////////////////////////////////////////////////
// static long double Duplication_Formula(long double two_x)                  //
//                                                                            //
//  Description:                                                              //
//     This function returns the Gamma(two_x) using the duplication formula   //
//     Gamma(2x) = (2^(2x-1) / sqrt(pi)) Gamma(x) Gamma(x+1/2).               //
//                                                                            //
//  Arguments:                                                                //
//     none                                                                   //
//                                                                            //
//  Return Values:                                                            //
//     Gamma(two_x)                                                           //
//                                                                            //
//  Example:                                                                  //
//     long double two_x, g;                                                  //
//                                                                            //
//     g = Duplication_Formula(two_x);                                        //
////////////////////////////////////////////////////////////////////////////////
static long double Duplication_Formula( long double two_x )
{
   long double x = 0.5L * two_x;
   long double g;
   double two_n = 1.0;
   int n = (int) two_x - 1;

   g = powl(2.0L, two_x - 1.0L - (long double) n);
   g = ldexpl(g,n);
   g /= sqrt(pi);
   g *= xGamma_Function(x);
   g *= xGamma_Function(x + 0.5L);

   return g;
}


////////////////////////////////////////////////////////////////////////////////
// double Gamma_Function_Max_Arg( void )                                      //
//                                                                            //
//  Description:                                                              //
//     This function returns the maximum argument of Gamma_Function for which //
//     a number < DBL_MAX is returned, for arguments greater than 1.          //
//                                                                            //
//  Arguments:                                                                //
//     none                                                                   //
//                                                                            //
//  Return Values:                                                            //
//     max_double_arg (171.0).                                                //
//                                                                            //
//  Example:                                                                  //
//     double x;                                                              //
//                                                                            //
//     x = Gamma_Function_Max_Arg();                                          //
////////////////////////////////////////////////////////////////////////////////
double Gamma_Function_Max_Arg( void ) { return max_double_arg; }


////////////////////////////////////////////////////////////////////////////////
// long double xGamma_Function_Max_Arg( void )                                //
//                                                                            //
//  Description:                                                              //
//     This function returns the maximum argument of Gamma_Function for which //
//     a number < LDBL_MAX is returned, for arguments greater than 1.         //
//                                                                            //
//  Arguments:                                                                //
//     none                                                                   //
//                                                                            //
//  Return Values:                                                            //
//     max_long_double_arg (1755.5).                                          //
//                                                                            //
//  Example:                                                                  //
//     long double x;                                                         //
//                                                                            //
//     x = xGamma_Function_Max_Arg();                                         //
////////////////////////////////////////////////////////////////////////////////
long double xGamma_Function_Max_Arg( void ) { return max_long_double_arg; }

////////////////////////////////////////////////////////////////////////////////
// double Ln_Beta_Function( double a, double b)                               //
//                                                                            //
//  Description:                                                              //
//     This function returns ln(Beta(a,b)) where a > 0 and b > 0.             //
//                                                                            //
//  Arguments:                                                                //
//     double a   Argument of the Beta function, a must be positive.          //
//     double b   Argument of the Beta function, b must be positive.          //
//                                                                            //
//  Return Values:                                                            //
//     log( beta(a,b) )                                                       //
//                                                                            //
//  Example:                                                                  //
//     double a, b, beta;                                                     //
//                                                                            //
//     beta = Ln_Beta_Function( a, b );                                       //
////////////////////////////////////////////////////////////////////////////////
double Ln_Beta_Function(double a, double b)
{
   return (double) xLn_Beta_Function( (long double) a, (long double) b );
}


////////////////////////////////////////////////////////////////////////////////
// long double xLn_Beta_Function( long double a, long double b)               //
//                                                                            //
//  Description:                                                              //
//     This function returns ln(Beta(a,b)) where a > 0 and b > 0.             //
//                                                                            //
//  Arguments:                                                                //
//     long double a   Argument of the Beta function, a must be positive.     //
//     long double b   Argument of the Beta function, b must be positive.     //
//                                                                            //
//  Return Values:                                                            //
//     log( beta(a,b) )                                                       //
//                                                                            //
//  Example:                                                                  //
//     long double a, b;                                                      //
//     long double beta;                                                      //
//                                                                            //
//     beta = xLn_Beta_Function( a, b );                                      //
////////////////////////////////////////////////////////////////////////////////

long double xLn_Beta_Function(long double a, long double b)
{

     // If (a + b) <= Gamma_Function_Max_Arg() then simply return //
     //  log(gamma(a)*gamma(b) / gamma(a+b)).                     //

   if ( (a + b) <= (long double) Gamma_Function_Max_Arg() )
      if ( a == 1.0L && b == 1.0L ) return 0.0L;
      else return logl( xGamma_Function(a) /
                             ( xGamma_Function(a + b) / xGamma_Function(b) ));

     // If (a + b) > Gamma_Function_Max_Arg() then simply return //
     //  lngamma(a) + lngamma(b) - lngamma(a+b).                 //

   return xLn_Gamma_Function(a) + xLn_Gamma_Function(b)
                                                  - xLn_Gamma_Function(a+b);
}

////////////////////////////////////////////////////////////////////////////////
// double Beta_Function( double a, double b)                                  //
//                                                                            //
//  Description:                                                              //
//     This function returns beta(a,b) = gamma(a) * gamma(b) / gamma(a+b),    //
//     where a > 0, b > 0.                                                    //
//                                                                            //
//  Arguments:                                                                //
//     double a   Argument of the Beta function, a must be positive.          //
//     double b   Argument of the Beta function, b must be positive.          //
//                                                                            //
//  Return Values:                                                            //
//     If beta(a,b) exceeds DBL_MAX then DBL_MAX is returned otherwise        //
//     beta(a,b) is returned.                                                 //
//                                                                            //
//  Example:                                                                  //
//     double a, b, beta;                                                     //
//                                                                            //
//     beta = Beta_Function( a, b );                                          //
////////////////////////////////////////////////////////////////////////////////
double Beta_Function(double a, double b)
{
   long double beta = xBeta_Function( (long double) a, (long double) b);
   return (beta < DBL_MAX) ? (double) beta : DBL_MAX;
}


////////////////////////////////////////////////////////////////////////////////
// long double xBeta_Function( long double a, long double b)                  //
//                                                                            //
//  Description:                                                              //
//     This function returns beta(a,b) = gamma(a) * gamma(b) / gamma(a+b),    //
//     where a > 0, b > 0.                                                    //
//                                                                            //
//  Arguments:                                                                //
//     long double a   Argument of the Beta function, a must be positive.     //
//     long double b   Argument of the Beta function, b must be positive.     //
//                                                                            //
//  Return Values:                                                            //
//     If beta(a,b) exceeds LDBL_MAX then LDBL_MAX is returned otherwise      //
//     beta(a,b) is returned.                                                 //
//                                                                            //
//  Example:                                                                  //
//     long double a, b;                                                      //
//     long double beta;                                                      //
//                                                                            //
//     beta = xBeta_Function( a, b );                                         //
////////////////////////////////////////////////////////////////////////////////
long double xBeta_Function(long double a, long double b)
{
   long double lnbeta;

     // If (a + b) <= Gamma_Function_Max_Arg() then simply return //
     //  gamma(a)*gamma(b) / gamma(a+b).                          //

   if ( (a + b) <= Gamma_Function_Max_Arg() )
      return xGamma_Function(a) / (xGamma_Function(a + b) / xGamma_Function(b));

     // If (a + b) > Gamma_Function_Max_Arg() then simply return //
     //  exp(lngamma(a) + lngamma(b) - lngamma(a+b) ).           //

   lnbeta = xLn_Gamma_Function(a) + xLn_Gamma_Function(b)
                                                 - xLn_Gamma_Function(a + b);
   return (lnbeta > ln_LDBL_MAX) ? (long double) LDBL_MAX : expl(lnbeta);
}

////////////////////////////////////////////////////////////////////////////////
// double Beta_Distribution( double x, double a, double b )                   //
//                                                                            //
//  Description:                                                              //
//     The beta distribution is the integral from -inf to x of the density    //
//                               0                if t <= 0,                  //
//                 t^(a-1) (1-t)^(b-1) / B(a,b)   if 0 < t < 1,               //
//                               0                if t >= 1,                  //
//     where a > 0, b > 0, and B(a,b) is the (complete) beta function.        //
//                                                                            //
//     For 0 < x < 1 the procedure for evaluating the beta distribution uses  //
//     the continued fraction expansion for the beta distribution:            //
//            beta(x,a,b) = [x^a * (1-x)^b / (a B(a,b))]                      //
//                                        * ( (1/1+)(d[1]/1+)(d[2]/1+)... )   //
//     where d[2m+1] = - (a+m)(a+b+m)x/((a+2m)(a+2m+1))                       //
//           d[2m] = m(b-m)x/((a+2m)(a+2m-1)),                                //
//     the symmetry relation:                                                 //
//           beta(x,a,b) = 1 - beta(1-x,b,a),                                 //
//     the recurrence relations:                                              //
//           beta(x,a+1,b) = beta(x,a,b+1) - x^a (1-x)^b / (b * B(a+1,b)),    //
//           beta(x,a,b+1) = beta(x,a+1,b) + x^a (1-x)^b / (a * B(a,b+1)),    //
//     and the interrelationship:                                             //
//           beta(x,a,b) = [a * beta(x,a+1,b) + b * beta(x,a,b+1)] / (a+b).   //
//                                                                            //
//     If both a > 1 and b > 1, then                                          //
//        if x <= (a-1) / ( a+b-2), then                                      //
//           use the continued fraction expansion                             //
//        otherwise                                                           //
//           use the symmetry relation and use the continued fraction         //
//           expansion to evaluate beta(1-x,b,a).                             //
//                                                                            //
//     If a < 1 and b > 1, then                                               //
//        use the interrelationship equation together with the recurrence     //
//        relation to evaluate                                                //
//           beta(x,a,b) = beta(x,a+1,b) + [x^a * (1-x)^b] / [a * B(a,b)].    //
//                                                                            //
//     If a > 1 and b < 1, then                                               //
//        use the interrelationship equation together with the recurrence     //
//        relation to evaluate                                                //
//           beta(x,a,b) = beta(x,a,b+1) - [x^a * (1-x)^b] / [b * B(a,b)].    //
//                                                                            //
//     If a < 1 and b < 1, then                                               //
//        use the interrelationship equation to evaluate                      //
//           beta(x,a,b) = [a * beta(x,a+1,b) + b * beta(x,a,b+1)] / (a+b).   //
//        in terms of beta distributions which now have one shape parameter   //
//        > 1.                                                                //
//                                                                            //
//     If a == 1, then evaluate the integral explicitly,                      //
//           beta(x,a,b) = [1 - (1-x)^b] / [b * B(a,b)].                      //
//                                                                            //
//     If b == 1, then evaluate the integral explicitly,                      //
//           beta(x,a,b) = x^a / [a * B(a,b)].                                //
//                                                                            //
//                                                                            //
//  Arguments:                                                                //
//     double x   Argument of the beta distribution.  If x <= 0, the result   //
//                is 0 and if x >= 1, the result is 1, otherwise the result   //
//                is the integral above.                                      //
//     double a   A positive shape parameter of the beta distriubtion,        //
//                a - 1 is the exponent of the factor x in the integrand.     //
//     double b   A positive shape parameter of the beta distribution,        //
//                b - 1 is the exponent of the factor (1-x) in the integrand. //
//                                                                            //
//  Return Values:                                                            //
//     A real number between 0 and 1.                                         //
//                                                                            //
//  Example:                                                                  //
//     double a, b, p, x;                                                     //
//                                                                            //
//     p = Beta_Distribution(x, a, b);                                        //
////////////////////////////////////////////////////////////////////////////////

double Beta_Distribution(double x, double a, double b)
{

   if ( x <= 0.0 ) return 0.0;
   if ( x >= 1.0 ) return 1.0;

   return (double) xBeta_Distribution( x, a, b);
}


////////////////////////////////////////////////////////////////////////////////
// long double xBeta_Distribution( double x, double a, double b )             //
//                                                                            //
//  Description:                                                              //
//     The incomplete beta function is the integral from 0 to x of            //
//                    t^(a-1) (1-t)^(b-1) dt,                                 //
//     where 0 <= x <= 1, a > 0 and b > 0.                                    //
//                                                                            //
//     The procedure for evaluating the incomplete beta function uses the     //
//     continued fraction expansion for the incomplete beta function:         //
//        beta(x,a,b) = x^a * (1-x)^b / a * ( (1/1+)(d[1]/1+)(d[2]/1+)...)    //
//     where d[2m+1] = - (a+m)(a+b+m)x/((a+2m)(a+2m+1))                       //
//           d[2m] = m(b-m)x/((a+2m)(a+2m-1)),                                //
//     the symmetry relation:                                                 //
//           beta(x,a,b) = B(a,b) - beta(1-x,b,a)                             //
//     where B(a,b) is the complete beta function,                            //
//     the recurrence relations:                                              //
//           beta(x,a+1,b) = a/b beta(x,a,b+1) - x^a (1-x)^b / b              //
//           beta(x,a,b+1) = b/a beta(x,a+1,b) + x^a (1-x)^b / a,             //
//     and the interrelationship:                                             //
//           beta(x,a,b) = beta(x,a+1,b) + beta(x,a,b+1).                     //
//                                                                            //
//     If both a > 1 and b > 1, then                                          //
//        if x <= (a-1) / ( a+b-2), then                                      //
//           use the continued fraction expansion                             //
//        otherwise                                                           //
//           use the symmetry relation and use the continued fraction         //
//           expansion to evaluate beta(1-x,b,a).                             //
//                                                                            //
//     If a < 1 and b > 1, then                                               //
//        use the interrelationship equation together with the recurrence     //
//        relation to evaluate                                                //
//           beta(x,a,b) = [(a+b) beta(x,a+1,b) + x^a (1-x)^b]/a.             //
//                                                                            //
//     If a > 1 and b < 1, then                                               //
//        use the interrelationship equation together with the recurrence     //
//        relation to evaluate                                                //
//           beta(x,a,b) = [(a+b) beta(x,a,b+1) - x^a (1-x)^b]/b.             //
//                                                                            //
//     If a < 1 and b < 1, then                                               //
//        use the interrelationship equation to evaluate                      //
//           beta(x,a,b) = beta(x,a+1,b) + beta(x,a,b+1)                      //
//        in terms of beta functions which now have one shape parameter > 1.  //
//                                                                            //
//     If a == 1, then evaluate the integral explicitly,                      //
//           beta(x,a,b) = [1 - (1-x)^b]/b.                                   //
//                                                                            //
//     If b == 1, then evaluate the integral explicitly,                      //
//           beta(x,a,b) = x^a / a.                                           //
//                                                                            //
//                                                                            //
//  Arguments:                                                                //
//     long double x   Upper limit of the incomplete beta function integral,  //
//                     x must be in the closed interval [0,1].                //
//     long double a   Shape parameter of the incomplete beta function, a - 1 //
//                     is the exponent of the factor x in the integrand.      //
//     long double b   Shape parameter of the incomplete beta function, b - 1 //
//                     is the exponent of the factor (1-x) in the integrand.  //
//                                                                            //
//  Return Values:                                                            //
//     beta(x,a,b)                                                            //
//                                                                            //
//  Example:                                                                  //
//     long double a, b, beta, x;                                             //
//                                                                            //
//     beta = xIncomplete_Beta_Function(x, a, b);                             //
////////////////////////////////////////////////////////////////////////////////

static long double xBeta_Distribution(double xx, double aa, double bb) 
{
   long double x = (long double) xx;
   long double a = (long double) aa;
   long double b = (long double) bb;

           /* Both shape parameters are strictly greater than 1. */

   if ( aa > 1.0 && bb > 1.0 )
      if ( x <= (a - 1.0L) / ( a + b - 2.0L ) )
         return Beta_Continued_Fraction(x, a, b);
      else
         return 1.0L - Beta_Continued_Fraction( 1.0L - x, b, a );
  
             /* Both shape parameters are strictly less than 1. */

   if ( aa < 1.0 && bb < 1.0 )  
      return (a * xBeta_Distribution(xx, aa + 1.0, bb) 
                      + b * xBeta_Distribution(xx, aa, bb + 1.0) ) / (a + b); 
   
              /* One of the shape parameters exactly equals 1. */

   if ( aa == 1.0 )
      return 1.0L - powl(1.0L - x, b) / ( b * xBeta_Function(a,b) );

   if ( bb == 1.0 ) return powl(x, a) / ( a * xBeta_Function(a,b) );

      /* Exactly one of the shape parameters is strictly less than 1. */

   if ( aa < 1.0 )  
      return xBeta_Distribution(xx, aa + 1.0, bb)
            + powl(x, a) * powl(1.0L - x, b) / ( a * xBeta_Function(a,b) );
 
                   /* The remaining condition is b < 1.0 */

   return xBeta_Distribution(xx, aa, bb + 1.0)
            - powl(x, a) * powl(1.0L - x, b) / ( b * xBeta_Function(a,b) );
}


////////////////////////////////////////////////////////////////////////////////
// long double Beta_Continued_Fraction( long double x, long double a,         //
//                                                            long double b ) //
//                                                                            //
//  Description:                                                              //
//     The continued fraction expansion used to evaluate the incomplete beta  //
//     function is                                                            //
//        beta(x,a,b) = x^a * (1-x)^b / a * ( (1/1+)(d[1]/1+)(d[2]/1+)...)    //
//     where d[2m+1] = - (a+m)(a+b+m)x/((a+2m)(a+2m+1))                       //
//           d[2m] = m(b-m)x/((a+2m)(a+2m-1)).                                //
//                                                                            //
//     where a > 1, b > 1, and x <= (a-1)/(a+b-2).                            //
//                                                                            //
//  Arguments:                                                                //
//     long double x   Upper limit of the incomplete beta function integral,  //
//                     x must be in the closed interval [0,1].                //
//     long double a   Shape parameter of the incomplete beta function, a - 1 //
//                     is the exponent of the factor x in the integrand.      //
//     long double b   Shape parameter of the incomplete beta function, b - 1 //
//                     is the exponent of the factor (1-x) in the integrand.  //
//                                                                            //
//  Return Values:                                                            //
//     beta(x,a,b)                                                            //
//                                                                            //
//  Example:                                                                  //
//     long double a, b, beta, x;                                             //
//                                                                            //
//     beta = Beta_Continued_Fraction(x, a, b);                               //
////////////////////////////////////////////////////////////////////////////////
static long double Beta_Continued_Fraction( long double x, long double a,
                                                                 long double b)
{
   long double Am1 = 1.0L;
   long double A0 = 0.0L;
   long double Bm1 = 0.0L;
   long double B0 = 1.0L;
   long double e = 1.0L;
   long double Ap1 = A0 + e * Am1;
   long double Bp1 = B0 + e * Bm1;
   long double f_less = Ap1 / Bp1;
   long double f_greater = 0.0L;
   long double aj = a;
   long double am = a;
   static long double eps = 10.0L * LDBL_EPSILON;
   int j = 0;
   int m = 0;
   int k = 1;

   if ( x == 0.0L ) return 0.0L;
   
   while ( (2.0L * fabsl(f_greater - f_less) > eps * fabsl(f_greater + f_less)) ) {
      Am1 = A0;
      A0 = Ap1;
      Bm1 = B0;
      B0 = Bp1;
      am = a + m;
      e = - am * (am + b) * x / ( (aj + 1.0L) * aj );
      Ap1 = A0 + e * Am1;
      Bp1 = B0 + e * Bm1;
      k = (k + 1) & 3;
      if (k == 1) f_less = Ap1/Bp1;
      else if (k == 3) f_greater = Ap1/Bp1;
      if ( fabsl(Bp1) > 1.0L) {
         Am1 = A0 / Bp1;
         A0 = Ap1 / Bp1;
         Bm1 = B0 / Bp1;
         B0 = 1.0;
      } else {
         Am1 = A0;
         A0 = Ap1;
         Bm1 = B0;
         B0 = Bp1;
      }
      m++;
      j += 2;
      aj = a + j;
      e = m * ( b - m ) * x / ( ( aj - 1.0L) * aj  );
      Ap1 = A0 + e * Am1;
      Bp1 = B0 + e * Bm1;
      k = (k + 1) & 3;
      if (k == 1) f_less = Ap1/Bp1;
      else if (k == 3) f_greater = Ap1/Bp1;
   }
   return expl( a * logl(x) + b * logl(1.0L - x) + logl(Ap1 / Bp1) ) /
                                                ( a * xBeta_Function(a,b) );
}

////////////////////////////////////////////////////////////////////////////////
// double Student_t_Distribution( double x, int n )                           //
//                                                                            //
//  Description:                                                              //
//     If X and X2 are independent random variables, X being N(0,1) and       //
//     X2 being Chi_Square with n degrees of freedom, then the random         //
//     variable T = X / sqrt(X2/n) has a Student-t distribution with n        //
//     degrees of freedom.                                                    //
//                                                                            //
//     The Student-t distribution is the Pr[T < x] which equals the integral  //
//     from -inf to x of the density                                          //
//            1/ [n^(1/2)* B(1/2,n/2)] * (1 + x^2/n)^(-(n+1)/2)               //
//     where n >= 1 and B(,) is the (complete) beta function.                 //
//                                                                            //
//     By making the change of variables: g = n / (n + x^2),                  //
//                   t(x,n) = 1 - B(n / (n + x^2), n/2, 1/2) / 2              //
//     where B(,,) is the incomplete beta function.                           //
//                                                                            //
//  Arguments:                                                                //
//     double x   The upper limit of the integral of the density given above. //
//     int    n   The number of degrees of freedom.                           //
//                                                                            //
//  Return Values:                                                            //
//     A real number between 0 and 1.                                         //
//                                                                            //
//  Example:                                                                  //
//     double p, x;                                                           //
//     int    n;                                                              //
//                                                                            //
//     p = Student_t_Distribution(x, n);                                      //
////////////////////////////////////////////////////////////////////////////////

double Student_t_Distribution(double x, int n)
{
   double a = (double) n / 2.0;
   double beta = Beta_Distribution( 1.0 / (1.0 + x * x / n), a, 0.5);

   if ( x > 0.0 ) return 1.0 - 0.5 * beta;
   else if ( x < 0.0) return 0.5 * beta;
   return 0.5;
}


////////////////////////////////////////////////////////////////////////////////
// double Student_t_Density( double x, int n )                                //
//                                                                            //
//  Description:                                                              //
//     The density of the Student-t distribution is                           //
//            1/ [n^(1/2)* B(1/2,n/2)] * (1 + x^2/n)^(-(n+1)/2)               //
//     where n >= 1 and B(,) is the (complete) beta function.                 //
//                                                                            //
//  Arguments:                                                                //
//     double x   The upper limit of the integral of the density given above. //
//     int    n   The number of degrees of freedom.                           //
//                                                                            //
//  Return Values:                                                            //
//     1/ [n^(1/2)* B(1/2,n/2)]*(1 + x^2/n)^(-(n+1)/2) evaluated at x and n.  //
//                                                                            //
//  Example:                                                                  //
//     double p, x;                                                           //
//     int    n;                                                              //
//                                                                            //
//     p = Student_t_Density(x, n);                                           //
////////////////////////////////////////////////////////////////////////////////

double Student_t_Density( double x, int n )
{
   double ln_density;

   ln_density = -(double)(n+1)/2.0 * log(1.0 + x * x /(double)n)
                - 0.5*log((double)n)
                - Ln_Beta_Function(0.5 * (double)n, 0.5);

   return exp(ln_density);
}
