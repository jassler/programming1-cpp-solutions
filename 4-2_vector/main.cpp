#include <iostream>
#include <conio.h>
#include <vector>

void a();
void b(std::vector<double> temperature);
void c(std::vector<double> temperature);
void d(size_t width, size_t height);


int main()
{
	/*
	 * a) enter grades for the exam
	 */
	std::cout << "a)\n";
	a();

	/*
	 * b) Celsius to Fahrenheit conversion
	 */
	std::cout << "\n\nb)\n";
	b({ 0.3, 0.5, 1.4, 3, 2.7, 1.2, 0, -0.1, -0.3, -0.9 });

	/*
	 * c) Vector modifications
	 */
	std::cout << "\n\nc)\n";
	c({ 0.3, 0.5, 1.4, 3, 2.7, 1.2, 0, -0.1, -0.3, -0.9 });
	
	/*
	 * d) Checker pattern
	 */
	std::cout << "\n\nd)\n";
	d(20, 20);

}



/*
 * a)
 */
void a()
{
	std::vector<int> grades;

	std::cout << "Enter your grades. When you're done, press enter.\n";

	/* ENTER GRADES */
	while (true)
	{
		std::cout << grades.size() + 1 << ". grade: ";

		char c = _getch();
		std::cout << c << "\n";

		// check if we now have to calculate the average
		if (c == '\n' || c == '\r')
			break;

		// convert char to integer and add it to the grades
		if (c < '1' || c > '6')
			std::cout << "Only enter grades from 1 through 6!\n";
		else
			grades.push_back(c - '0');
	}

	/* AVOID EDGE CASE */
	if (grades.size() == 0)
	{
		std::cout << "No average to calculate!\n";
		return;
	}

	/* CALCULATE AVERAGE AND SHOW PROCESS */
	std::cout << "(";
	
	auto it = grades.begin();
	int sum = *it;
	std::cout << *it;

	while (++it != grades.end())
	{
		std::cout << " + " << *it;
		sum += *it;
	}

	std::cout << ") / " << grades.size() << " = " << (double)sum / grades.size() << '\n';
}



/*
 * b)
 */
void b(std::vector<double> temperature)
{
	std::cout << "Celsius values are ";
	for (auto t : temperature) std::cout << t << ' ';

	// conversion
	for (auto& t : temperature)
	{
		t = t * 1.8 + 32.0;
	}

	// result
	std::cout << "\nFahrenheit values are ";
	for (auto t : temperature) std::cout << t << ' ';
}



/*
 * c)
 */
void c(std::vector<double> temperature)
{
	std::cout << "Original values: ";
	for (auto t : temperature) std::cout << t << ' ';

	// we're assuming that the temperature size is at least 3 and that we only want to chip off the outer two values
	std::vector<double> new_vector(temperature.begin() + 1, temperature.end() - 1);

	std::cout << "\nChipped off the ends: ";
	for (auto t : new_vector) std::cout << t << ' ';

	// remove negative numbers
	for (auto it = new_vector.begin(); it != new_vector.end();)
	{
		if (*it < 0)
			it = new_vector.erase(it);
		else
			++it;
	}

	std::cout << "\nRemoved negative numbers: ";
	for (auto t : new_vector) std::cout << t << ' ';

	// add averages
	// insert adds value before
	for (auto it = new_vector.begin(); it < new_vector.end() - 1; ++it)
	{
		double a1 = *it++;
		double a2 = *it;
		double avg = (a1 + a2) / 2;

		// it points to the inserted value
		it = new_vector.insert(it, avg);
	}

	std::cout << "\nAdded averages: ";
	for (auto t : new_vector) std::cout << t << ' ';
}



/*
 * d)
 */
void d(size_t width, size_t height)
{
	// 8x8 field of empty characters (or width x height field for that matter)
	std::vector<std::vector<char>> board(height, std::vector<char>(width, ' '));

	// fill all odd spots
	for (int y = 0; y < board.size(); y++)
	{
		for (int x = 0; x < board[y].size(); x++)
		{
			if ((x + y) % 2 == 1)
				board[y][x] = '#';
		}
	}

	// print it
	for (auto& row : board)
	{
		for (auto c : row)
			std::cout << c;
		std::cout << '\n';
	}
}
