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

double &Matrix2x2::operator()(int row, int column) {
    if(row >= MATRIX_DIM || row < 0 || column >= MATRIX_DIM || column < 0){
        throw std::invalid_argument("index out of range");
    }
    return matrix[row][column];
}

const double &Matrix2x2::operator()(int row, int column) const {
    if(row >= MATRIX_DIM || row < 0 || column >= MATRIX_DIM || column < 0){
        throw std::invalid_argument("index out of range");
    }
    return matrix[row][column];
}

double Matrix2x2::getDeterminant() {
    double A[MATRIX_DIM][MATRIX_DIM];
    double ratio;
    double det = 1;

    int i, j, k, l, m;
    // writing matrix content on A - matrix
    for(i = 0; i < MATRIX_DIM; i++){
        for(int j = 0; j < MATRIX_DIM; j++){
            A[i][j] = this->matrix[i][j];
        }
    }
    // Gaussian elimination
    for(k = 0; k < MATRIX_DIM-1; k++){
        if(A[k][k] == 0.0){
            return 0.0;
        }
        for(l = k+1; l < MATRIX_DIM; l++){
            if(k!=l){
                ratio = (A[l][k] / A[k][k]);
            }
            for(m = 0; m < MATRIX_DIM; m++){
                A[l][m] = A[l][m] - ratio * A[k][m];
            }
        }
    }
    // Calculating determinant using now diagonal A matrix
    for(int t = 0; t < MATRIX_DIM; t++){
        det *= A[t][t];
    }

    return det;
}
