#include <iostream>
#include <string>
#include <map>

void str_to_lower(std::string& s)
{
	for (auto& l : s)
	{
		l = tolower(l);
	}
}

std::string prompt_string(std::string prompt = "")
{
	std::string result;

	while (result.empty())
	{
		std::cout << prompt;
		std::getline(std::cin, result);
	}

	return result;
}

void print_cities(const std::map<std::string, size_t>& population)
{
	// structured binding, a feature of C++17
	// for alternatives, check here: https://stackoverflow.com/a/26282004
	for (auto const& [city, pop] : population)
	{
		std::cout << city << ": " << pop << '\n';
	}
}

void add_city(std::map<std::string, size_t>& population)
{
	std::string name = prompt_string("City name: ");
	str_to_lower(name);

	// check if name already in map
	if (population.count(name))
	{
		std::cout << name << " already exists. Remove it before setting its value\n";
		return;
	}


	/* Ask for number */
	size_t pop;
	std::string pop_str;

	while (true)
	{
		pop_str = prompt_string("City size: ");

		// check if it only contains digits
		if (pop_str.find_first_not_of("0123456789") != std::string::npos)
			std::cout << "Only enter digits!\n";

		// check if number is too long (no city should have more than 1 trillion people
		// (hopefully)
		// also, check if size_t on your machine is 64 bit or 32 bit (in which case it cannot exceed somewhere around 4.3 billion)
		else if (pop_str.size() > 13)
			std::cout << "Number too long!\n";

		else
			break;
	}

	// success! convert and insert!
	pop = std::stoul(pop_str);
	population[name] = pop;
}

void remove_city(std::map<std::string, size_t>& population)
{
	std::string city = prompt_string("City to remove: ");
	str_to_lower(city);

	// ignores if city doesn't even exist
	population.erase(city);
}

int main()
{
	std::map<std::string, size_t> population;

	/* different ways of adding key / value pairs */
	// Replaces old value (if existent)
	population["berlin"] = 3748000;

	// ignored if value present
	population.insert(std::make_pair("hamburg", 1822000));

	// data generated in-place
	population.emplace("kempten", 68330);
	/* ... */

	while (true) {
		print_cities(population);

		std::cout << "\nWhat do you want to do?\n"
			"\ta - add a new city\n"
			"\tr - remove an existing city\n"
			"\tc - clear table\n";

		std::string command = prompt_string("?: ");
		system("cls");
		
		switch (tolower(command[0]))
		{
		case 'a': add_city(population);    break;
		case 'r': remove_city(population); break;
		case 'c': population.clear();      break;

		default:
			std::cout << "Unknown command, try another\n";
		}

		std::cout << "\n";
	}
}
