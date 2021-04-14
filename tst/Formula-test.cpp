#include "gtest/gtest.h"
#include "Matrix2x2.h"
#include <iostream>
#include <utility>
#include "Rectangle.h"
#include "Constants.h"
#include "Vector.h"



TEST (Vector1, EmptyConstructor) {

    Vector Vec1 = Vector();
    Vector Vec2 = Vector();
    Vec1.setX(0);
    Vec1.setY(0);
    EXPECT_EQ(Vec1, Vec2);
}

TEST (Vector2, Constructor) {

    Vector Vec1 = Vector(2.3,4.5);
    Vector Vec2 = Vector();
    Vec2.setX(2.3);
    Vec2.setY(4.5);
    EXPECT_EQ(Vec1, Vec2);
}

TEST (Vector3, Addition) {

    Vector Vec1 = Vector(2.3,4.5);
    Vector Vec2 = Vector(1,1);

    EXPECT_EQ(Vec1 + Vec2, Vector(3.3, 5.5));
}

TEST (Vector4, Subtruction) {

    Vector Vec1 = Vector(2.3,4.5);
    Vector Vec2 = Vector(1,1);

    EXPECT_EQ(Vec1 - Vec2, Vector(1.3, 3.5));
}

TEST (Vector5, Multiplication) {

    Vector Vec1 = Vector(2,4);

    EXPECT_EQ(Vec1 * 2, Vector(4, 8));
}

TEST (Vector6, Division) {

    Vector Vec1 = Vector(2,4);

    EXPECT_EQ(Vec1 / 2, Vector(1, 2));
}

TEST (Vector7, FailDivision) {

    Vector Vec1 = Vector(2,4);

    EXPECT_THROW(Vec1 / 0, std::invalid_argument);
}

TEST (Vector8, FailIndexing) {

    Vector Vec1 = Vector(2,4);

    EXPECT_THROW(Vec1[3], std::invalid_argument);
}

TEST (Vector9, Indexing) {

    Vector Vec1 = Vector(2,4);

    EXPECT_EQ(Vec1[1], 4);
}

TEST (Vector10, Ostream) {

    std::stringstream ost;
    Vector vec = Vector(3.1,3.1);
    ost << vec;
    EXPECT_EQ("3.1 3.1\n", ost.str());
}

TEST (Vector11, GetLength) {

    Vector Vec1 = Vector(3,4);
    double length = Vec1.getLength();
    EXPECT_EQ(length, 5);
}

TEST (Matrix1, EmptyConstructor) {
    Matrix2x2 A = Matrix2x2();
    Matrix2x2 B = Matrix2x2();

    B.setMatrix(0,0,0,0);
    EXPECT_EQ(A, B);
}

TEST (Matrix2, Constructor) {

    Matrix2x2 A = Matrix2x2(90);
    Matrix2x2 B = Matrix2x2();

    Matrix2x2 C = Matrix2x2(0);
    Matrix2x2 D = Matrix2x2();

    B.setMatrix(cos(M_PI/2),-sin(M_PI/2),sin(M_PI),cos(M_PI/2));
    D.setMatrix(cos(0),-sin(0),sin(0),cos(0));
    EXPECT_EQ(A, B);
    EXPECT_EQ(C, D);

}

TEST (Matrix3, MultiplicationMatrixVector) {

    Matrix2x2 A = Matrix2x2();
    Vector vec = Vector(1,1);
    Vector result = Vector();

    A.setMatrix(1,2,3,4);
    result = A*vec;

    EXPECT_EQ(result, Vector(3,7));
}

TEST (Matrix4, MultiplicationMatrixVector) {

    Matrix2x2 A = Matrix2x2();
    Vector vec = Vector(1,1);
    Vector result = Vector();

    A.setMatrix(1,2,3,4);
    result = A*vec;

    EXPECT_EQ(result, Vector(3,7));
}

TEST (Matrix5, Indexing) {

    Matrix2x2 A = Matrix2x2();
    Matrix2x2 B = Matrix2x2();
    Vector vec = Vector(1,1);
    Vector result = Vector();

    B(0,0) = 1;
    B(0,1) = 2;
    B(1,0) = 3;
    B(1,1) = 4;
    A.setMatrix(1,2,3,4);
    result = A*vec;

    EXPECT_EQ(result, Vector(3,7));
}

TEST (Matrix6, FailIndexing) {

    Matrix2x2 A = Matrix2x2();
    Vector vec = Vector(1,1);
    Vector result = Vector();

    A.setMatrix(1,2,3,4);
    result = A*vec;

    EXPECT_THROW(A(2,4), std::invalid_argument);
}

TEST (Rectangle1, EmptyConstructor) {

    Rectangle Adam = Rectangle();
    Rectangle Ewa = Rectangle();

    Vector Vec0 = Vector();
    Vector Vec1 = Vector();
    Vector Vec2 = Vector();
    Vector Vec3 = Vector();
    Vector Vec4 = Vector();
    Ewa.setRectangle(Vec0, Vec1, Vec2, Vec3, Vec4);

    EXPECT_EQ(Adam, Ewa);
}

TEST (Rectangle2, ConstructorWithVerticesInOrder) {

    Vector Ver1 = Vector(1,3);
    Vector Ver2 = Vector(3,3);
    Vector Ver3 = Vector(3,1);
    Vector Ver4 = Vector(1,1);

    Rectangle Adam = Rectangle(Ver1, Ver2, Ver3, Ver4);
    Rectangle Ewa = Rectangle();

    Vector center = Vector(2,2);

    Ewa.setRectangle(center, Ver1, Ver2, Ver3, Ver4);

    EXPECT_EQ(Adam, Ewa);
}

TEST (Rectangle3, ConstructorWithMixedUpVerticesInArguments) {

    Vector Ver1 = Vector(1,3);
    Vector Ver2 = Vector(3,3);
    Vector Ver3 = Vector(3,1);
    Vector Ver4 = Vector(1,1);

    Rectangle Adam = Rectangle(Ver2, Ver1, Ver4, Ver3);
    Rectangle Ewa = Rectangle();

    Vector center = Vector(2,2);

    Vector Vec1 = Vector(1,3);
    Vector Vec2 = Vector(3,3);
    Vector Vec3 = Vector(3,1);
    Vector Vec4 = Vector(1,1);
    Ewa.setRectangle(center, Vec1, Vec2, Vec3, Vec4);

    EXPECT_EQ(Adam, Ewa);
}

TEST (Rectangle4, TranslationByWector) {

    Vector Ver1 = Vector(1,3);
    Vector Ver2 = Vector(3,3);
    Vector Ver3 = Vector(3,1);
    Vector Ver4 = Vector(1,1);
    Vector translation = Vector(1,1);

    Rectangle Adam = Rectangle(Ver1, Ver2, Ver3, Ver4);
    Rectangle Ewa = Rectangle();
    Adam.translationByVector(translation);
    Vector center = Vector(3,3);
    Vector Vec1 = Vector(2,4);
    Vector Vec2 = Vector(4,4);
    Vector Vec3 = Vector(4,2);
    Vector Vec4 = Vector(2,2);

    Ewa.setRectangle(center, Vec1, Vec2, Vec3, Vec4);

    EXPECT_EQ(Adam, Ewa);
}

TEST (Rectangle5, RotationByDegrees) {

    Vector Ver1 = Vector(1, 3);
    Vector Ver2 = Vector(3, 3);
    Vector Ver3 = Vector(3, 1);
    Vector Ver4 = Vector(1, 1);
    Vector translation = Vector(1, 1);

    Rectangle Adam = Rectangle(Ver1, Ver2, Ver3, Ver4);
    Rectangle Ewa = Rectangle();
    Adam.rotationByDegrees(90);

    Vector center = Vector(-2, 2);
    Vector Vec1 = Vector(-3, 1);
    Vector Vec2 = Vector(-3, 3);
    Vector Vec3 = Vector(-1, 3);
    Vector Vec4 = Vector(-1, 1);

    Ewa.setRectangle(center, Vec1, Vec2, Vec3, Vec4);

    EXPECT_EQ(Adam, Ewa);
}

TEST (Rectangle6, RectangleOstream) {

    std::stringstream ost;
    Vector Ver1 = Vector(1, 3);
    Vector Ver2 = Vector(3, 3);
    Vector Ver3 = Vector(3, 1);
    Vector Ver4 = Vector(1, 1);

    Rectangle Adam = Rectangle(Ver1, Ver2, Ver3, Ver4);
    ost << Adam;

    EXPECT_EQ("1 3\n3 3\n3 1\n1 1\n", ost.str());
}

TEST (Rectangle7, GetSidesLength) {

    std::stringstream ost;
    Vector Ver1 = Vector(1, 3);
    Vector Ver2 = Vector(3, 3);
    Vector Ver3 = Vector(1, 1);
    Vector Ver4 = Vector(3, 1);

    Rectangle Adam = Rectangle(Ver1, Ver2, Ver3, Ver4);
    std::pair<double,double> sides = Adam.getSidesLength(Ver1, Ver2, Ver3, Ver4);
    double shorterSide = sides.first;
    double longerSide = sides.second;

    EXPECT_EQ(shorterSide, 2);
    EXPECT_EQ(longerSide, 2);
}

TEST (Rectangle8, Indexing) {

std::stringstream ost;
Vector Ver1 = Vector(1, 3);
Vector Ver2 = Vector(3, 3);
Vector Ver3 = Vector(1, 1);
Vector Ver4 = Vector(3, 1);

Rectangle Adam = Rectangle(Ver1, Ver2, Ver3, Ver4);


EXPECT_EQ(Adam[0], Ver1);
EXPECT_EQ(Adam[1], Ver2);
EXPECT_EQ(Adam[2], Ver3);
EXPECT_EQ(Adam[3], Ver4);

}