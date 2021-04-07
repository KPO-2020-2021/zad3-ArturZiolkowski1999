//
// Created by artur on 3/17/21.
//



#ifndef ROTATION2D_RECTANGLE_H
#define ROTATION2D_RECTANGLE_H
#include <iostream>
#include <utility>
#include <float.h>
#include "Matrix2x2.h"
#include "Constants.h"
#include "Vector.h"

class Rectangle {
private:
    /*Vector points from 0,0 to center of mas*/
    Vector centerOfMass;
    /*Vector from center of mass to vertices*/
    Vector verticesFromCenter[VERTICES_NUMBER];
    void sortVertices(Vector &Vec1, Vector &Vec2, Vector &Vec3, Vector &Vec4);

public:
    Rectangle();
    /* constructor get cord of 4 vertices of rectangle*/
    /* ver3 and ver2 have to bo on diagonal, Vec 3 has to be left down corner*/
    Rectangle(Vector &ver1, Vector &ver2, Vector &ver3, Vector &ver4);
    /* Set all parameters strictly */
    void setRectangle(Vector &center, Vector &ver1, Vector &ver2, Vector &ver3, Vector &ver4);
    friend bool operator==(const Rectangle &Rect1, const Rectangle &Rect2);
    void rotationByDegrees(double degree);
    void translationByVector(Vector &Vec);
    friend std::ostream & operator<<(std::ostream & ost, Rectangle &Rect);
    std::pair<double, double> getSidesLength(Vector &ver1, Vector &ver2, Vector &ver3, Vector &ver4);
//    friend std::istream & operator>>(std::istream & ist, Rectangle &Rect);


};
#endif //ROTATION2D_RECTANGLE_H
