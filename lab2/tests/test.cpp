#include "../3d_geometry.hpp"
#include <iostream>
#include <stdio.h>
// #include "catch2/catch.hpp"

// #define CATCH_CONFIG_MAIN

// geometry::Sphere sphere(0,0,0,5);
// // geometry::Cuboid cuboid(0,0,0,3,5,6);
// // geometry::Cube cube(0,0,0,5);


// TEST_CASE("Check sphere methods") {
//     REQUIRE(sphere.surface_area() == 314);
//     REQUIRE((sphere.volume() > 523 && sphere.volume() < 524));
// }
// TEST_CASE("Check cube methods") {
//     REQUIRE(cube.surface_area() == 150);
//     REQUIRE(cube.volume() == 125);
// }


// TEST_CASE("Check cuboid methods") {
//     REQUIRE(cuboid.surface_area() == 140);
//     REQUIRE(cuboid.volume() == 90);
// }

int main() {

    geometry::Sphere sphere(0,0,0,5);
    std::cout << "Sphere: volume =" << sphere.volume() << ", should be 523.33" << "\n";
    std::cout << "Sphere: surface area =" << sphere.surface_area() << ",should be 314" "\n";

    geometry::Cuboid cuboid(0,0,0, 3,5,6);
    std::cout << "Cuboid: volume =" << cuboid.volume() << ", should be 90" << "\n";
    std::cout << "Cuboid: surface area =" << cuboid.surface_area() << ", should be 126" << "\n";
 
    geometry::Cube cube(0,0,0,5);
    std::cout << "Cube: volume =" << cube.volume() << ", should be 125" << "\n";
    std::cout << "Cube: surface area =" << cube.surface_area() << ", should be 150" << "\n";
    return 0;
}