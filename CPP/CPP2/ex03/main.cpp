#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 10);

	Point inside(5, 5);
	Point outside(15, 5);
	Point onEdge(5, 0);

	std::cout << "Triangle vertices:" << std::endl;
	std::cout << "A(" << a.getX() << ", " << a.getY() << ")" << std::endl;
	std::cout << "B(" << b.getX() << ", " << b.getY() << ")" << std::endl;
	std::cout << "C(" << c.getX() << ", " << c.getY() << ")" << std::endl;
	std::cout << std::endl;

	std::cout << "Point (" << inside.getX() << ", " << inside.getY() << ") is ";
	if (bsp(a, b, c, inside))
		std::cout << "inside the triangle" << std::endl;
	else
		std::cout << "outside the triangle" << std::endl;

	std::cout << "Point (" << outside.getX() << ", " << outside.getY() << ") is ";
	if (bsp(a, b, c, outside))
		std::cout << "inside the triangle" << std::endl;
	else
		std::cout << "outside the triangle" << std::endl;

	std::cout << "Point (" << onEdge.getX() << ", " << onEdge.getY() << ") is ";
	if (bsp(a, b, c, onEdge))
		std::cout << "inside the triangle" << std::endl;
	else
		std::cout << "outside the triangle (on edge)" << std::endl;

	return 0;
}
