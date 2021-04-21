
#ifndef ROTATION2D_MATRIX_H
#define ROTATION2D_MATRIX_H

#include <ios>
#include "Vector.h"


class Matrix2x2 {
private:
    double matrix[MATRIX_DIM][MATRIX_DIM];

    double degreeToRadians(double degree);
public:
    double getDeterminant();
    Matrix2x2();
    Matrix2x2(double degree);
    void setMatrix(double a, double b, double c, double d);
    friend bool operator==(const Matrix2x2 &matrix1, const Matrix2x2 &matrix2);
    friend Vector operator*(const Matrix2x2 &matrix, Vector &vec);
    double &operator()(int row, int column);
    const double &operator()(int row, int column) const;
};

#endif //ROTATION2D_MATRIX_H