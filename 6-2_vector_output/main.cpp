#include <iostream>
#include <sstream>
#include <vector>

// a) <<
// T refers to a type. << therefore can be used only if T overloads that operator
// (as is the case for most data types)
template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> v) {
	
	auto it = v.begin();
	if (it != v.end()) {
		os << *it;
		while (++it != v.end())
			os << ' ' << *it;
	}

	return os;
}

// b) >>
template<typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v) {
	T tmp;
	std::string line;

	// have to read single line, otherwise std::cin doesn't know when to stop reading from console
	// note that for reading files, the while loop would suffice (no istringstream needed)
	if (std::getline(is, line)) {

		std::istringstream iss(line);
		while (iss >> tmp)
			v.push_back(tmp);
	}

	return is;
}

int main() {

	std::vector<double> v;

	while (true) {
		std::cout << "Give me some numbers (with spaces):";
		std::cin >> v;

		std::cout << "Vector currently is: " << v << "\n\n";
	}

}
