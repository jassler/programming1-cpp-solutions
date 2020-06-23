#pragma once
#include <iostream>

struct Point
{
	double x;
	double y;

	Point(double _x, double _y);

	// b) + and -
	// Operator overloading can be implemented as struct method.
	// LHS is indirectly declared as Point, RHS is defined by the parameter inside the braces.
	Point operator+(const Point& rhs);
	Point operator-(const Point& rhs);

	// f) += -= *= /=
	// Those operators must be defined here
	Point& operator+=(const Point& rhs);
	Point& operator-=(const Point& rhs);
	Point& operator*=(const double rhs);
	Point& operator/=(const double rhs);
};

// a) Comparison operators
// Operator overloading can be introduced completely independently
// from its struct / class.
bool operator==(const Point& a, const Point& b);
bool operator!=(const Point& a, const Point& b);

// c) * and / double
Point operator*(const Point& p, const double s);
Point operator*(const double s, const Point& p);
Point operator/(const Point& p, const double s);
Point operator/(const double s, const Point& p);

// d) Cross product
double operator*(const Point& a, const Point& b);

// e) Unary minus
Point operator-(const Point& a);

// g) <<
std::ostream& operator<<(std::ostream& os, const Point& p);
