#include "Point.hpp"

static Fixed abs(Fixed x) {
	if (x < Fixed(0))
		return x * Fixed(-1);
	return x;
}

static Fixed area(Point const a, Point const b, Point const c) {
	Fixed area = ((a.getX() * (b.getY() - c.getY())) +
				  (b.getX() * (c.getY() - a.getY())) +
				  (c.getX() * (a.getY() - b.getY()))) / Fixed(2);
	return abs(area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed totalArea = area(a, b, c);
	Fixed area1 = area(point, b, c);
	Fixed area2 = area(a, point, c);
	Fixed area3 = area(a, b, point);

	// Points on edges or vertices have at least one sub-area equal to zero
	if (area1 == Fixed(0) || area2 == Fixed(0) || area3 == Fixed(0))
		return false;

	// Using fixed-point arithmetic ensures deterministic equality checks
	// No floating-point precision issues since all operations use integer math
	return (totalArea == (area1 + area2 + area3));
}
