#include <iostream>
#include <conio.h>
#include <string>
#include <array>

void b();
void c();
void d();
void e();
void f();

int main(int argc, char* argv[])
{
	/*
	 * a) Turn char* into string
	 */
	std::cout << "a)\n";
	for (int x = 0; x < argc; x++)
	{
		// this is basically it
		std::string arg(argv[x]);
		std::cout << "Argument " << x << " is " << arg << " and has " << arg.size() << " letters\n";
	}


	/*
	 * b) implement is_password_correct
	 */
	std::cout << "\nb)\n";
	b();

	/*
	 * c) One char 50 times, please
	 */
	std::cout << "\nc)\n";
	c();

	/*
	 * d) ADD EXCITEMENT!!11!!1ELF
	 */
	std::cout << "\nd)\n";
	d();

	/*
	 * e) Reverse string
	 */
	std::cout << "\ne)\n";
	e();


	/*
	 * f) Reverse sentence
	 */
	std::cout << "\nf)\n";
	f();	

	std::cout << "\n\nDone!";
}



/*
 * b)
 */
bool is_password_correct(std::string password, std::string input)
{
	return password == input;
}

void b()
{
	std::cout << "Enter a password: ";
	std::string password_input;
	std::getline(std::cin, password_input);

	if (is_password_correct("secret", password_input))
		std::cout << "Password is correct!\n";
	else
		std::cout << "Password is incorrect :(\nWho cares, let's continue\n";
}



/*
 * c)
 */
void c()
{
	std::cout << "One char please: ";
	char c = _getch();

	std::cout << c << '\n';

	// repeat char c 50 times
	std::string long_string(50, c);
	std::cout << "String initialized. Value is:\n" << long_string << '\n';
}



/*
 * d)
 */
void add_excitement(std::string& msg, unsigned int excitement_level)
{
	if (excitement_level > 4)
	{
		// capitalize message
		for (auto& letter : msg)
			letter = toupper(letter);
	}

	// note, a normal array could have sufficed as well
	// there are multiple exclamation points because I want those most often
	std::array<std::string, 10> to_append{ "!", "!", "!", "!", "!", "!", "1", "1", "EINS", "ELF" };

	for (unsigned int x = 0; x < excitement_level; x++)
	{
		msg += to_append[rand() % to_append.size()];
	}
}

void d()
{
	std::cout << "Enter your message: ";

	std::string excitement_msg;
	std::getline(std::cin, excitement_msg);

	std::cout << "Enter your excitement level (positive number or 0): ";
	unsigned int level = 0;

	while (true)
	{
		std::string line;
		std::getline(std::cin, line);
		try {
			level = std::stoi(line);
			break;
		}
		catch (...) {
			std::cout << "Please enter a valid, positive number.\n";
		}
	}

	add_excitement(excitement_msg, level);
	std::cout << excitement_msg << "\n";
}



/*
 * e)
 */
std::string reverse_string(std::string input)
{
	std::string result;
	result.reserve(input.size());

	// reverse iterate through input
	for (auto it = input.rbegin(); it < input.rend(); ++it)
	{
		result.push_back(*it);
	}

	return result;
}

void e()
{
	std::cout << "\ne)\n";
	std::cout << "Enter message to be reversed: ";

	std::string to_reverse_string, reversed_string;
	std::getline(std::cin, to_reverse_string);

	std::string reversed_string = reverse_string(to_reverse_string);
	std::cout << "Reversed string: " << reversed_string << "\n";
}



/*
 * f)
 */
void skip_whitespace(size_t& index, std::string& s)
{
	while (index < s.size() && s[index] == ' ')
		index++;
}


std::string reverse_words_in_sentence(std::string sentence)
{
	// one letter sentence doesn't have to be reversed
	if (sentence.size() < 2)
		return sentence;

	size_t start = 0;
	size_t end;

	do
	{
		// start of next word!
		skip_whitespace(start, sentence);

		// find returns index of specified letter found after start
		// if not found, it returns string::npos = a really really high number
		end = sentence.find(' ', start);

		// substring of sentence
		// note that the substring method ignores really really high end-points
		// so if end == string::npos, it'll just return a substring from start to the end of string
		std::string word(sentence, start, end - start);

		// reverse and replace
		word = reverse_string(word);
		sentence.replace(start, word.size(), word);

		// look for word after end
		start = end + 1;
	} while (end != std::string::npos);
	
	return sentence;
}

void f()
{
	std::string to_reverse_string, reversed_string;

	std::cout << "Enter sentence to be reversed: ";
	std::getline(std::cin, to_reverse_string);

	reversed_string = reverse_words_in_sentence(to_reverse_string);
	std::cout << reversed_string << "\n";
}
