//
// Created by Stas Sidelnikov on 2019-09-17.
//

#ifndef QUADRATIC_EQUATION_SOLVER_SQR_EQ_H
#define QUADRATIC_EQUATION_SOLVER_SQR_EQ_H
#define INF_ROOTS -1
#define eps 1e-6
#include <stdio.h>

#include "sqr_eq.cpp"



/// Enters equation's coefficietns
/// @param [in] a - coefficient
/// @param [in] b - coefficient
/// @param [in] c - coeffieient

int enter_coefficients(float* a, float* b, float* c);

/// Checks if float value is equal to int value with a certain error
/// @param[in] a float value
/// @param[in] b int value
/// @returns 1 if a = b, 0 of a != b
int is_number(float a, int b);

/// Solves linear equation
/// @param[in] a - coefficient
/// @param[in] b - coefficient
/// @param[in] x - pointer to the root
/// @returns number of roots
int solve_linear(float a, float b, float* x);

/// Solvers a quadratic equation ax^2 + bx + c = 0, returns number of roots.
/// @param [in] a a - coefficient
/// @param [in] b b - coefficient
/// @param [in] c c - coefficient
/// @param [out] x1 - pointer to the 1st root
/// @param [out] x2 - pointer to the 2nd root
/// @returns number of roots
/// @note In case of infinite amount of roots return  constant defined expression  INF_ROOTS
int square_solve(float a, float b, float c, float* x1, float* x2);

#endif //QUADRATIC_EQUATION_SOLVER_SQR_EQ_H
