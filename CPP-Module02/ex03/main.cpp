#include <iostream>
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    // テストケース
    Point p1(3, 3);   // Inside
    Point p2(10, 10); // Outside
    Point p3(0, 0);   // Vertex (A) -> False expected
    Point p4(5, 0);   // On Edge (AB) -> False expected
    Point p5(0.1f, 0.1f); // Just Inside

    std::cout << "Inside(3,3): " << bsp(a, b, c, p1) << " (Expected: 1)" << std::endl;
    std::cout << "Outside(10,10): " << bsp(a, b, c, p2) << " (Expected: 0)" << std::endl;
    std::cout << "Vertex(0,0): " << bsp(a, b, c, p3) << " (Expected: 0)" << std::endl;
    std::cout << "Edge(5,0): " << bsp(a, b, c, p4) << " (Expected: 0)" << std::endl;
    std::cout << "JustIn(0.1,0.1): " << bsp(a, b, c, p5) << " (Expected: 1)" << std::endl;

    return 0;
}