//
// Created by justagod on 3/14/20.
//

#include <cmath>
#include <string>
#include <iostream>
#include "primitives.h"

using namespace std;

double Circle::square() const {
    return M_PI * r * r;
}

double Circle::perimeter() const {
    return 2 * M_PI * r;
}

void Circle::draw() const {
    cout << "I'm circle. r = " << r << ", pos = {" << pos.x << ", " << pos.y << "}";
}

const char *circle_name = "Circle";
const char *Circle::classname() {
    return circle_name;
}

unsigned int Circle::size() {
    return 4 + 8;
}

void Circle::initFromDialog() {
    cout << "Radius: ";
    cin >> r;
    pos.initFromDialog();
}

Vector2D::Vector2D() = default;

void Vector2D::initFromDialog() {
    cout << "Pos.x: ";
    cin >> x;
    cout << "Pos.y: ";
    cin >> y;
}

double EquilateralTriangle::square() const {
    return pow(3, 0.5) / 4 * a * a;
}

double EquilateralTriangle::perimeter() const {
    return a * 3;
}

void EquilateralTriangle::initFromDialog() {
    cout << "Edge: ";
    cin >> a;
    pos.initFromDialog();
}

void EquilateralTriangle::draw() const {
    cout << "I'm equilateral triangle. a = " << a << ", pos = {" << pos.x << ", " << pos.y << "}";
}

const char *isosceles_triangle_name = "EquilateralTriangle";
const char *EquilateralTriangle::classname() {
    return isosceles_triangle_name;
}

unsigned int EquilateralTriangle::size() {
    return 4 + 8;
}

double GeometricFigure::mass() const {
    return square();
}

Vector2D GeometricFigure::position() const {
    return pos;
}

bool GeometricFigure::operator==(const PhysObject &ob) const {
    return ob.mass() == mass();
}

bool GeometricFigure::operator<(const PhysObject &ob) const {
    return mass() < ob.mass();
}
