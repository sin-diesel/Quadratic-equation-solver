//
// Created by Stas Sidelnikov on 2019-09-17.
//
#include "sqr_eq.h"

int enter_coefficients(float* a, float* b, float* c) {
    int correct = scanf("%f %f %f", a, b, c);
    if (correct != 3) {
        correct = scanf("%f %f %f", a, b, c);
        printf("Wrong input\n");
    }

}
/// Checks if float value is equal to int value with a certain error
/// @param[in] a float value
/// @param[in] b int value
/// @returns 1 if a = b, 0 of a != b
int is_number(float a, int b) {
    assert(isfinite(a));
    assert(isfinite(b));
    if (abs(a - b) < eps) {
        return 1;
    } else {
        return 0;
    }
}

/// Solves linear equation
/// @param[in] a - coefficient
/// @param[in] b - coefficient
/// @param[in] x - pointer to the root
/// @returns number of roots
int solve_linear(float a, float b, float* x) {
    assert(isfinite(a));
    assert(isfinite(b));

    int n_roots = 0;
    if (is_number(a, 0)) {
        if (is_number(b, 0)) {
            n_roots = INF_ROOTS;
            return n_roots;
        } else {
            n_roots = 0;
            return n_roots;
        }
    } else {
        *x = -b / a;
        n_roots = 1;
        return n_roots;
    }
}

/// Solvers a quadratic equation ax^2 + bx + c = 0, returns number of roots.
/// @param [in] a a - coefficient
/// @param [in] b b - coefficient
/// @param [in] c c - coefficient
/// @param [out] x1 - pointer to the 1st root
/// @param [out] x2 - pointer to the 2nd root
/// @returns number of roots
/// @note In case of infinite amount of roots return  constant defined expression  INF_ROOTS
int square_solve(float a, float b, float c, float* x1, float* x2) {
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1 != x2);

    int n_roots = 0;
    if (is_number(a, 0)) {
        n_roots = solve_linear(b, c, x1);
        return n_roots;
    } else {
        if (is_number(b, 0)) {
            if ((-c / a) > 0) {
                float sqr = sqrt(-c / a);
                *x1 = sqr;
                *x2 = -sqr;
                n_roots = 2;
                return n_roots;
            } else {
                n_roots = 0;
                return n_roots;
            }
        } else {
            float d = b * b - 4 * a * c;
            if (d < 0) {
                n_roots = 0;
                return n_roots;
            }
            else {
                float sqr_d = sqrt(d);
                *x1 = ((-b - sqr_d) / 2 / a);
                *x2 = ((-b + sqr_d) / 2 / a);
                n_roots = 2;
                return n_roots;
            }
        }
    }
}

