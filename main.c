#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#define INF_ROOTS -1
#define eps 1e-6

#include "sqr_eq.h"

int main () {
    float a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    printf("Enter equation coefficients: \n");

    enter_coefficients(&a, &b, &c);

    int n_roots = square_solve(a, b, c, &x1, &x2);

    switch (n_roots) {
        case 0:
            printf("No roots\n");
            break;
        case 1:
            printf("Single root: %f", x1);
            break;
        case 2:
            printf("Two roots: %f, %f", x1, x2);
            break;
        case INF_ROOTS:
            printf("Infinite amount of roots");
            break;
        default:
            printf("System error has occured");
    }

    return 0;
}