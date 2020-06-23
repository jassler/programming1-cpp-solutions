#include "6_1_tests.h"
#include "Point.h"
#include <iostream>
#include <sstream>
#include <cassert>

#define TEST_EQ(a,b) if(!((a)==(b))){ fails++; std::cout << "Line " << __LINE__ << ", test failed, a == b returned false (" << (#a) << " == " << (#b) << ") in file " << __FILE__ << "\n"; }
#define TEST_NEQ(a,b) if(!((a)==(b))){ fails++; std::cout << "Line " << __LINE__ << ", test failed, a != b returned false (" << (#a) << " != " << (#b) << ") in file " << __FILE__ << "\n"; }
#define TEST_TRUE(a) if(!(a)){ fails++; std::cout << "Line " << __LINE__ << ", test failed, expression should have returned true (" << (#a) << ") in file " << __FILE__ << "\n"; }
#define TEST_FALSE(a) if(a){ fails++; std::cout << "Line " << __LINE__ << ", test failed, expression should have returned false (" << (#a) << ") in file " << __FILE__ << "\n"; }

void test_equality(unsigned int& fails) {
	TEST_TRUE(Point(1, 1) == Point(1, 1));
	TEST_TRUE(Point(1, -1) == Point(1, -1));
	TEST_FALSE(Point(1, -1) == Point(-1, 1));
	TEST_FALSE(Point(1, 1) == Point(-1, 1));
	TEST_FALSE(Point(-1, -1) == Point(-1, 1));

	TEST_FALSE(Point(1, 1) != Point(1, 1));
	TEST_FALSE(Point(1, -1) != Point(1, -1));
	TEST_TRUE(Point(1, -1) != Point(-1, 1));
	TEST_TRUE(Point(1, 1) != Point(-1, 1));
	TEST_TRUE(Point(-1, -1) != Point(-1, 1));
}

void test_addition_subtraction(unsigned int& fails) {
	TEST_EQ(Point(1, 2) + Point(4, 2), Point(5, 4));
	TEST_EQ(Point(-2.5, -1) + Point(-1, -2.5), Point(-3.5, -3.5));

	TEST_EQ(Point(1, 2) - Point(4, 2), Point(-3, 0));
	TEST_EQ(Point(-2.5, -1) - Point(-1, -2.5), Point(-1.5, 1.5));
}

void test_multiply_scalar(unsigned int& fails) {
	TEST_EQ(Point(2, 3) * 5, Point(10, 15));
	TEST_EQ(-4 * Point(5, -1), Point(-20, 4));

	TEST_EQ(Point(2, 3) / 5, Point(2.0 / 5, 3.0 / 5));
	TEST_EQ(4 / Point(2, 3), Point(2, 4.0 / 3));
}

void test_cross_product(unsigned int& fails) {
	TEST_EQ(Point(1, 2) * Point(-4, 2), 0);
	TEST_EQ(Point(3, 4) * Point(-1, -2), -11);
}

void test_unary_minus(unsigned int& fails) {
	TEST_EQ(-Point(3, -2), Point(-3, 2));
	TEST_EQ(-Point(0, 1), Point(0, -1));
}

void test_inline_arithmetic(unsigned int& fails) {
	Point a(1, 44);

	a += Point(4, -4);
	TEST_EQ(a, Point(5, 40));

	a = Point(3, 5);
	a -= Point(4, 7);
	TEST_EQ(a, Point(-1, -2));

	a = Point(1, -0.25);
	a *= 4;
	TEST_EQ(a, Point(4, -1));

	a = Point(4, -1);
	a /= 4;
	TEST_EQ(a, Point(1, -0.25));
}

void test_output(unsigned int& fails) {
	Point a(3, -2.5);

	std::stringstream ss;
	ss << a;

	TEST_EQ(ss.str(), "Point(3,-2.5)");
}

unsigned int test_overloads() {
	unsigned int fails = 0;

	test_equality(fails);
	test_addition_subtraction(fails);
	test_multiply_scalar(fails);
	test_cross_product(fails);
	test_unary_minus(fails);
	test_inline_arithmetic(fails);
	test_output(fails);

	return fails;
}
