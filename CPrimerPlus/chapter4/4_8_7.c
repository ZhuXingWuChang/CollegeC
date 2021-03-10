#include <stdio.h>
#include <float.h>
int main(void)
{
    double d_variable = 1.0 / 3.0;
    float f_variable = 1.0 / 3.0;

    printf("the value of double: %.6lf  , the value of float: %.6f\n",
           d_variable, f_variable);
    printf("the value of double: %.12lf  , the value of float: %.12f\n",
           d_variable, f_variable);
    printf("the value of double: %.16lf  , the value of float: %.16f\n",
           d_variable, f_variable);
    printf("FLT_DIG = %d    , FLT_DIG = %d\n", FLT_DIG, DBL_DIG);

    return 0;
}