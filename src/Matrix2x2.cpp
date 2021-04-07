#include "Matrix2x2.h"
#include "Vector.h"

Matrix2x2::Matrix2x2() {
    int i = 0;
    int j = 0;
    while(i<MATRIX_DIM){
        while(j<MATRIX_DIM){
            this->matrix[i][j] = 0;
            j++;
        }
        i++;
    }
}

Matrix2x2::Matrix2x2(double degree) {
    /* [cos(), -sin(), ...]
     * [sin(),  cos(), ...]
     * [..................] */
    int i = 2;
    int j = 2;
    double radians = degreeToRadians(degree);
    this->matrix[0][0] = cos(radians);
    this->matrix[0][1] = -sin(radians);
    this->matrix[1][0] = sin(radians);
    this->matrix[1][1] = cos(radians);

    while(i<MATRIX_DIM){
        while(j<MATRIX_DIM){
            /*2x times assign because all left matrix symmetrically should be zeroed */
            this->matrix[i][j] = 0;
            this->matrix[j][i] = 0;
            j++;
        }
        i++;
    }
}

double Matrix2x2::degreeToRadians(double degree){
    return degree * M_PI / 180;
}

void Matrix2x2::setMatrix(double a, double b, double c, double d){
    /* [a, b, ...]
     * [c, d, ...]
     * [.........] */

    this->matrix[0][0] = a;
    this->matrix[0][1] = b;
    this->matrix[1][0] = c;
    this->matrix[1][1] = d;

    int i = 2;
    int j = 2;
    while(i < MATRIX_DIM){
        while(j < MATRIX_DIM){
            /*2x times assign because all left matrix symmetrically should be zeroed */
            this->matrix[i][j] = 0;
            this->matrix[j][i] = 0;
            j++;
        }
        i++;
    }
}

bool operator==(const Matrix2x2 &matrix1, const Matrix2x2 &matrix2){
    int i = 0;
    int j = 0;
    while(i < MATRIX_DIM){
        while(j < MATRIX_DIM){
            if(std::abs(matrix1.matrix[i][j] - matrix2.matrix[i][j]) > MIN_THRESHOLD){
                return false;
            }
            j++;
        }
        i++;
    }
    return true;
}

Vector operator*(const Matrix2x2 &matrix, Vector &vec){
    Vector result = Vector();
    result.setX(vec.getX() * matrix.matrix[0][0] + vec.getY() * matrix.matrix[0][1]);
    result.setY(vec.getX() * matrix.matrix[1][0] + vec.getY() * matrix.matrix[1][1]);
    return result;
}