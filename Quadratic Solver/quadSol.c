#include <math.h>
int quad_roots(double * A, double * roots)
{
    // int discriminant = (A[1]*A[1]) - (4*(A[2]*A[0]));
    if (A[2] == 0)
    {
        if (A[1] == 0)
        {
            if (A[0] == 0)
            {
                // no meaningful solution
                return -2;
            }
            else
            {
                //not an equation
                return -3;
            }
        }else
        {
            //it's a linear equation with one solution in roots[0]
            roots[0] = -(A[0]/A[1]);
            return -1;
        }
    }
    else
    {
        if ((A[1]*A[1]) > (4*(A[2]*A[0])))
        {
            //two different real roots
            // calculate x with (+)root and store it in roots[0]
            roots[0] = ((-(A[1])) + (sqrt((A[1]*A[1]) - (4*(A[2]*A[0]))))) / (2*(A[2]));
            
            // calculate x with (-)root and store it in roots[1]
            roots[1] = ((-(A[1])) - (sqrt((A[1]*A[1]) - (4*(A[2]*A[0]))))) / (2*(A[2]));
            return 0;
        }
        else
        {
            if ((A[1]*A[1]) < (4*(A[2]*A[0])))
            {
                // solutions are complex conjugate roots: roots[0] is real, roots[1] is i
                /* not sure here... */
                roots[0] = ((-(A[1])) + (sqrt((A[1]*A[1]) - (4*(A[2]*A[0]))))) / (2*(A[2]));
                roots[1] = ((-(A[1])) - (sqrt((A[1]*A[1]) - (4*(A[2]*A[0]))))) / (2*(A[2]));
                return 1;
            }
            else
            {
                // so this means (A[1]*A[1]) == (4*(A[2]*A[0])), so the roots[0] and [1] are equal
                roots[0] = ((-(A[1])) + (sqrt((A[1]*A[1]) - (4*(A[2]*A[0]))))) / (2*(A[2]));
                roots[1] = ((-(A[1])) - (sqrt((A[1]*A[1]) - (4*(A[2]*A[0]))))) / (2*(A[2]));
                return 2;
            }
        }
    }
}