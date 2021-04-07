
#ifndef ROTATION2D_MATRIX_H
#define ROTATION2D_MATRIX_H
#include <iostream>
#include <ios>
#include <cmath>
#include "Constants.h"


class Vector;
class Matrix2x2 {
private:
    double matrix[MATRIX_DIM][MATRIX_DIM];

    double degreeToRadians(double degree);
public:
    Matrix2x2();
    Matrix2x2(double degree);
    void setMatrix(double a, double b, double c, double d);
    friend bool operator==(const Matrix2x2 &matrix1, const Matrix2x2 &matrix2);
    friend Vector operator*(const Matrix2x2 &matrix, Vector &vec);
};

#endif //ROTATION2D_MATRIX_H