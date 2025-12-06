#include <iostream>
#include "Point.hpp"

int main()
{
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(0.0f, 10.0f);

	Point p1(2.0f, 2.0f);
	Point p2(5.0f, 0.0f);
	Point p3(20.0f, 20.0f);

	std::cout << std::boolalpha;

	std::cout << "p1 inside ? " << bsp(a, b, c, p1) << std::endl;
	std::cout << "p2 inside ? " << bsp(a, b, c, p2) << std::endl;
	std::cout << "p3 inside ? " << bsp(a, b, c, p3) << std::endl;

	return 0;
}