//
// Created by artur on 3/17/21.
//
#include "Rectangle.h"
#include "Vector.h"

Rectangle::Rectangle(){
    for(int i = 0; i < VERTICES_NUMBER; i++){
        this->verticesFromCenter[i] = Vector();
    }
    this->centerOfMass = Vector();
}

void Rectangle::sortVertices(Vector &Vec1, Vector &Vec2, Vector &Vec3, Vector &Vec4){
    Vector vertices[VERTICES_NUMBER] = {Vec1, Vec2, Vec3, Vec4};
    Vector sortedVertices[VERTICES_NUMBER];
    //simple sort on vectors
    Vector smallest = Vector(DBL_MAX/2, DBL_MAX/2);
    int smallestIndex;
    for(int j = 0; j < VERTICES_NUMBER; j++) {
        for (int i = 0; i < VERTICES_NUMBER; i++) {
            if ((vertices[i].getX() + vertices[i].getY()) < (smallest.getX() + smallest.getY())) {
                smallest = vertices[i];
                smallestIndex = i;
            }
        }
        vertices[smallestIndex] = Vector(DBL_MAX/2, DBL_MAX/2);
        sortedVertices[j] = smallest;
        smallest = Vector(DBL_MAX/2, DBL_MAX/2);
    }
    //[0] -> Left down corner, [3] -> right up corner, [2][1] -> rest corners

    Vec1 = sortedVertices[1];
    Vec2 = sortedVertices[3];
    Vec3 = sortedVertices[0];
    Vec4 = sortedVertices[2];
}

Rectangle::Rectangle(Vector &ver1, Vector &ver2, Vector &ver3, Vector &ver4){

    sortVertices(ver1, ver2, ver3, ver4);

    Vector tmp1 = ver2 - ver3;
    Vector tmp2 = tmp1 / 2;
    Vector center = tmp2 + ver3;
    this->verticesFromCenter[0] = ver1 - center;
    this->verticesFromCenter[1] = ver2 - center;
    this->verticesFromCenter[2] = ver3 - center;
    this->verticesFromCenter[3] = ver4 - center;
    this->centerOfMass = center;
    for(int i = 4; i < VERTICES_NUMBER; i++){
        this->verticesFromCenter[i] = Vector();
    }
}

void Rectangle::setRectangle(Vector &center, Vector &ver1, Vector &ver2, Vector &ver3, Vector &ver4){
    this->verticesFromCenter[0] = ver1;
    this->verticesFromCenter[1] = ver2;
    this->verticesFromCenter[2] = ver3;
    this->verticesFromCenter[3] = ver4;
    this->centerOfMass = center;
}

bool operator==(const Rectangle &Rect1, const Rectangle &Rect2){
    if(Rect1.centerOfMass == Rect2.centerOfMass &&
        Rect1.verticesFromCenter[0] == Rect2.verticesFromCenter[0] &&
        Rect1.verticesFromCenter[1] == Rect2.verticesFromCenter[1] &&
        Rect1.verticesFromCenter[2] == Rect2.verticesFromCenter[2] &&
        Rect1.verticesFromCenter[3] == Rect2.verticesFromCenter[3] ){
        return true;
    }
    return false;
}

void Rectangle::translationByVector(Vector &Vec){
    this->centerOfMass = this->centerOfMass + Vec;
}

void Rectangle::rotationByDegrees(double degree){
    Matrix2x2 rotation = Matrix2x2(degree);
    this->verticesFromCenter[0] = rotation * (this->verticesFromCenter[0]);
    this->verticesFromCenter[1] = rotation * (this->verticesFromCenter[1]);
    this->verticesFromCenter[2] = rotation * (this->verticesFromCenter[2]);
    this->verticesFromCenter[3] = rotation * (this->verticesFromCenter[3]);
}

std::ostream & operator<<(std::ostream & ost, Rectangle &Rect){
    Vector Ver1 = Rect.verticesFromCenter[0] + Rect.centerOfMass;
    Vector Ver2 = Rect.verticesFromCenter[1] + Rect.centerOfMass;
    Vector Ver3 = Rect.verticesFromCenter[2] + Rect.centerOfMass;
    Vector Ver4 = Rect.verticesFromCenter[3] + Rect.centerOfMass;
    ost << Ver1 << Ver2 << Ver3 << Ver4 << std::endl;
    return ost;
}

std::pair<double, double> Rectangle::getSidesLength(Vector &ver1, Vector &ver2, Vector &ver3, Vector &ver4){
    sortVertices(ver1, ver2, ver3, ver4);
    //ver3 -> Left down corner, ver2 -> right up corner, ver1, ver4 -> rest corners
    std::pair<double, double> sides;
    double tmp;
    Vector side1 = ver3 - ver4;
    Vector side2 = ver3 - ver1;
    sides.first = side1.getLength();
    sides.second = side2.getLength();
    if(sides.first < sides.second){
        tmp = sides.first;
        sides.first = sides.second;
        sides.second = tmp;
    }
    return sides;
}