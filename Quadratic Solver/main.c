//
//  main.c
//  Quadratic Solver
//
#include <stdio.h>
#include <complex.h>

int quad_roots(double * A, double * r_roots); //declaring that there's a function quad_roots

int main(void)
{
    /* Create "double" type arrays to store coeffients A (3) and the roots (2) */
    double A[3], r_roots[2];
    double _Complex c_roots[2];
    
    /* Prompt for the coefficients */
    printf("Enter coefficients a, b, and c, of the Quadratic Equation in the form:\na*(x)^2 + bx + c\nin the order a, b, then c (separated by spaces):");
    // for the sake of clarity, a, b, c will be referred as A[2], A[1], A[0]
    scanf("%lf %lf %lf", A+2, A+1, A);
    
    
    /* Solve equation using function "quad_roots" (on file "quadSol.c")" */
    /* depending on the kind of discriminants */
    switch (quad_roots(A, r_roots)) {
        
        /* A[2] == A[1] == 0, where A[0] != 0, therefore not an equation */
        case -3:
            printf("case -3\na and b are the same... and equal to 0.\nAre you kidding?, that one is not an equation\n");
            break;
            
        /* A[0] == A[1] == A[2] == 0, ALL the coefficients are ceros */
        case -2:
            printf("case -2\nSorry, there is no meaningful solution, you know... like life\n");
            break;
            
        /* A[0] == 0 and A[1] != 0, this is a LINEAR equation, with just ONE solution */
        case -1:
            printf("case -1\nx = %f\nHey Einstein! This is not quadratic, it's a LINEAR equation\n",  r_roots[0]);
            break;
            
        /* (A[1])^2 > 4(A[2]*A[0]), discriminant > 0, there are two different real roots */
        case 0:
            printf("case 0\nx = %10.20f\nx = %10.20f\n",  r_roots[0],  r_roots[1]);
            break;
            
        /* (A[1])^2 < 4(A[2]*A[0]), discriminant < 0, solutions are complex conjugate roots */
        /* not sure here...!!!! */
        case 1:
            printf("case 1\nx = %10.20f (is a real number)\nx = i%10.20f (is an imaginary number)\n", creal(c_roots[1]), cimag(c_roots[1]));
            break;
            
        /* (A[1])^2 == 4(A[2]*A[0]), discriminant == 0, roots[0] == roots[1] ? */
        case 2:
            printf("case 2\nx = %10.20f is equal to:\nx = %10.20f\n",  r_roots[0],  r_roots[1]);
            break;

    }
    return 0;
}