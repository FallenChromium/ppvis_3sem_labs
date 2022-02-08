
#define PI 3.14
#include "3d_geometry.hpp"
#include <math.h>

geometry::SpacialShape::SpacialShape(float x, float y, float z) {
    this->_x = x;
    this->_y = y;
    this->_z = z;
}

geometry::SpacialShape::SpacialShape() {
    this->_x = this->_y = this->_z = 0;
}

float geometry::SpacialShape::getX() {
    return this->_x;
}

float geometry::SpacialShape::getY() {
    return this->_y;
}

float geometry::SpacialShape::getZ() {
    return this->_z;
}

float geometry::Sphere::surface_area() {
    return 4 * PI * pow(_radius, 2);
};


float geometry::Sphere::volume() {
    return 4./3 * PI * pow(_radius, 3);
};

float geometry::Cuboid::volume() {
    return _side_base_a * _side_base_b * _side_face;
};

float geometry::Cuboid::surface_area() {
    return 2*(_side_base_a * _side_base_b) + 2 * (_side_base_a * _side_face) + 2*(_side_base_b * _side_face);
}