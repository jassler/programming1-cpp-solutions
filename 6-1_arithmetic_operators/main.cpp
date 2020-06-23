#include "Point.h"
#include "6_1_tests.h"
#include <iostream>

int main() {
	unsigned int fails = test_overloads();

	std::cout << "Testing is done\n";

	if (fails == 0)
		std::cout << "No errors occured. Congrats!\n";
	else if (fails == 1)
		std::cout << "Encountered " << fails << " error\n";
	else
		std::cout << "Encountered " << fails << " errors\n";
}
