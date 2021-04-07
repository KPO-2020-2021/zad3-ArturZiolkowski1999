//
// Created by artur on 3/18/21.
//
#ifndef ROTATION2D_VECTOR_H
#define ROTATION2D_VECTOR_H
#include "Constants.h"
#include <iostream>
#include <iomanip>
#include <cmath>

class Vector {
private:
    double vector[VECTOR_DIM];
public:
    Vector();
    Vector(double _x, double _y);
    friend bool operator==(const Vector &Vec1, const Vector &Vec2);
    friend Vector operator+(Vector &Vec1, Vector &Vec2);
    friend Vector operator-(Vector &Vec1, Vector &Vec2);
    friend Vector operator/(Vector &Vec, const double &Num);
    friend Vector operator*(Vector &Vec, const double &Num);
    double getLength();
    void setX(double _x);
    void setY(double _y);
    double const getX();
    double const getY();
    friend std::ostream & operator<<(std::ostream & ost, const Vector &Vec);
};
#endif //ROTATION2D_VECTOR_H
