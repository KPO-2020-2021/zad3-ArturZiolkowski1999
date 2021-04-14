//
// Created by artur on 3/18/21.
//

#include "Vector.h"
Vector::Vector(){
    int i = 0;
    while(i < VECTOR_DIM) {
        this->vector[i] = 0;
        i++;
    }
}

Vector::Vector(double _x, double _y){
    this->vector[0] = _x;
    this->vector[1] = _y;
    int i = 2;
    while(i < VECTOR_DIM){
        this->vector[i] = 0;
        i++;
    }
}


bool operator==(const Vector &Vec1, const Vector &Vec2){
    if((std::abs(Vec1.vector[0] - Vec2.vector[0]) < MIN_THRESHOLD) &&
        (std::abs(Vec1.vector[1] - Vec2.vector[1]) < MIN_THRESHOLD)){
        return true;
    }
    return false;
}

Vector operator+(Vector &Vec1, Vector &Vec2){
    Vector result;
    result.setX(Vec1.getX() + Vec2.getX());
    result.setY(Vec1.getY() + Vec2.getY());
    return result;
}

Vector operator-(Vector &Vec1, Vector &Vec2){
    Vector result;
    result.setX(Vec1.getX() - Vec2.getX());
    result.setY(Vec1.getY() - Vec2.getY());
    return result;
}

Vector operator*(Vector &Vec, const double &Num){
    Vector result;
    result.setX(Vec.getX() * Num);
    result.setY(Vec.getY() * Num);
    return result;
}

Vector operator/(Vector &Vec, const double &Num){
    if(Num == 0){
        throw std::invalid_argument("division by zero");
    }
    Vector result;
    result.setX(Vec.getX() / Num);
    result.setY(Vec.getY() / Num);
    return result;
}

std::ostream & operator<<(std::ostream & ost, const Vector &Vec){
    std::cout << std::fixed;
    std::cout << std::setprecision(VECTOR_PRECISION);
    ost << Vec.vector[0] << " ";
    ost << Vec.vector[1] << std::endl;
    return ost;
}

void Vector::setX(double _x){
    this->vector[0] = _x;
}

void Vector::setY(double _y){
    this->vector[1] = _y;
}

double const Vector::getX(){
    return this->vector[0];
}

double const Vector::getY(){
    return this->vector[1];
}

double Vector::getLength(){
    double length = sqrt((this->getX()) * (this->getX()) + (this->getY()) * (this->getY()));
    return length;
}

const double &Vector::operator[](int index) const {
    switch (index) {
        case 0:
            return this->vector[0];
        case 1:
            return this->vector[1];
        default:
            throw std::invalid_argument("");
    }
}

double &Vector::operator[](int index) {
    switch (index) {
        case 0:
            return this->vector[0];
        case 1:
            return this->vector[1];
        default:
            throw std::invalid_argument("");
    }
}

std::istream &operator>>(std::istream &ist, Vector &Vec) {
    double x,y;
    std::cout << "enter x cord of vector:\n";
    ist >> x;
    Vec[0] = x;

    std::cout << "enter y cord of vector:\n";
    ist >> y;
    Vec[1] = y;

    return ist;
}
