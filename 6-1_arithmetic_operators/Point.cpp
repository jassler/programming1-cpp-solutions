#include "Point.h"

Point::Point(double _x, double _y)
	: x(_x), y(_y) {}

// a) Comparison operators
// Operator overloading can be introduced completely independently
// from its struct / class.
bool operator==(const Point& a, const Point& b) {
	return (a.x == b.x) && (a.y == b.y);
}

bool operator!=(const Point& a, const Point& b) {
	return (a.x != b.x) || (a.y != b.y);
}

// b) + and -
// This time defined in the struct. LHS is indirectly declared as Point.
Point Point::operator+(const Point& rhs) {
	return Point(x + rhs.x, y + rhs.y);
}

Point Point::operator-(const Point& rhs) {
	return Point(x - rhs.x, y - rhs.y);
}


// c) * and / double
// notice we could do (double * point) as well as (point * double)
Point operator*(const Point& p, const double s) {
	return Point(p.x * s, p.y * s);
}

Point operator*(const double s, const Point& p) {
	return Point(p.x * s, p.y * s);
}

// notice precedence matters for division
Point operator/(const Point& p, const double s) {
	return Point(p.x / s, p.y / s);
}


Point operator/(const double s, const Point& p) {
	return Point(s / p.x, s / p.y);
}

// d) Cross product
double operator*(const Point& a, const Point& b) {
	return a.x * b.x + a.y * b.y;
}

// e) Unary minus
Point operator-(const Point & a) {
	return Point(-a.x, -a.y);
}

// f) +=, -=, *=, /=
Point& Point::operator+=(const Point& rhs) {
	this->x += rhs.x;
	this->y += rhs.y;
	return *this;
}

Point& Point::operator-=(const Point& rhs) {
	this->x -= rhs.x;
	this->y -= rhs.y;
	return *this;
}

Point& Point::operator*=(const double rhs) {
	this->x *= rhs;
	this->y *= rhs;
	return *this;
}

Point& Point::operator/=(const double rhs) {
	this->x /= rhs;
	this->y /= rhs;
	return *this;
}

// g) <<
std::ostream& operator<<(std::ostream& os, const Point& p) {
	os << "Point(" << p.x << "," << p.y << ")";
	return os;
}
