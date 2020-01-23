#define _CRT_SECURE_NO_WARNINGS

#include "account.h"
#include "transaction.h"
#include <iostream>
#include <algorithm>
#include <exception>
#include <iomanip>
#include <sstream>
#include <fstream>

#define DELIMITER ";"
#define DATEFORMAT "%d.%m.%Y" DELIMITER "%H:%M"

// turn input into Transaction / Account
auto parse_line(std::istream& input)->Transaction;
auto read_transactions(std::istream& input)->Account;

// turn Account into output
void pipe_transactions(std::ostream& output, Account& a);

// user input house keeping
std::string prompt_string(std::string prompt);
Transaction prompt_transaction();

// Turn stream input into Transaction object
// Expects values to be separated by DELIMITER
// Throws std::runtime_error if parsing not successful
// If thrown, use error function what() to see what went wrong
Transaction parse_line(std::istream& input)
{
	Transaction t;
	char c;

	// Read datetime
	input >> std::get_time(&t.timestamp, DATEFORMAT);
	if (input.fail())
		throw std::runtime_error("Parsing the date failed, expected format " DATEFORMAT);

	// delimiter
	input >> c;
	if (c != DELIMITER[0])
		throw std::runtime_error("Expected delimiter " DELIMITER " right after date");

	// recipient and description
	std::getline(input, t.recipient, DELIMITER[0]);
	std::getline(input, t.description, DELIMITER[0]);

	// amount (in cents)
	input >> t.amount;

	if (input.bad())
		throw std::runtime_error("Bad bit set (might be caused by recipient, description or amount, or eof is reached to early)");

	return t;
}

// read stream until eof, parse each line into a Transaction object
// forwards runtime_error from calling parse_line
Account read_transactions(std::istream& input)
{

	Account a;
	Transaction t;

	std::string line;
	size_t line_num = 1;

	// breaks loop as soon as getline fails (eg. from reaching end of file (eof))
	while (std::getline(input, line))
	{
		// try parsing the next line, if successful then add it to account
		try {
			std::istringstream line_stream(line);
			t = parse_line(line_stream);
		}
		catch (std::runtime_error e)
		{
			// print line of error, forward exception
			std::stringstream error_msg;
			error_msg << "Error reading line " << line_num << ": " << e.what();
			throw std::runtime_error(error_msg.str().c_str());
		}

		a.add_transaction(t);
		line_num++;
	}

	return a;
}

// pipe transactions to an output stream
// output stream could be a filestream, cout, stringstream or similar
void pipe_transactions(std::ostream& output, Account& a)
{
	// don't add a new line character in the first line
	// (so file doesn't end in an empty line)
	bool firstline = true;

	for (auto transaction : a)
	{
		if (firstline)
			firstline = !firstline;
		else
			output << '\n';

		output << std::put_time(&transaction.timestamp, DATEFORMAT) << DELIMITER;
		output << transaction.recipient << DELIMITER;
		output << transaction.description << DELIMITER;
		output << transaction.amount;
	}
}

// Ask user for a string
// Will repeat question as long as user includes the delimiter in his input
std::string prompt_string(std::string prompt)
{
	std::string result;

	while (1)
	{
		std::cout << prompt;
		std::getline(std::cin, result);

		// make sure input doesn't contain delimiter
		if (std::find(result.begin(), result.end(), DELIMITER[0]) == result.end())
			break;

		std::cout << "Input shouldn't contain csv delimiter (" DELIMITER ")\n";
	}

	return result;
}

// Get user input for new transaction
Transaction prompt_transaction()
{
	Transaction t;

	t.recipient = prompt_string("Recipient: ");
	t.description = prompt_string("Description: ");

	// amount
	while (1)
	{
		std::string input = prompt_string("Amount (in cents): ");

		try
		{
			t.amount = std::atoi(input.c_str());
			break;
		}
		catch (...)
		{
			std::cout << "Error while converting " << input << " to a whole number. Try again.\n";
		}
	}

	// Transaction occured right now
	std::time_t current_time = std::time(0);
	t.timestamp = *std::localtime(&current_time);

	return t;
}

int main(int argc, char* argv[])
{
	Account a;

	// default csv filename
	std::string filename = "transactions.csv";

	// first argument can be given for csv filename
	if (argc > 1)
		filename = argv[1];

	std::cout << "Trying to read " << filename << "\n";
	std::fstream file(filename, std::fstream::in);

	if (!file.is_open())
	{
		std::cout << "Couldn't open " << filename << " (probably doesn't exist yet)\n";
	}
	else
	{
		// reading file could cause runtime_error
		try
		{
			a = read_transactions(file);
		}
		catch (std::runtime_error e)
		{
			// exit with failure case
			std::cerr << e.what();
			exit(1);
		}

		if (file.bad())
		{
			perror("error while trying to read file");
			exit(2);
		}
		file.close();
	}

	while (1)
	{
		std::cout << "\n\nCurrent balance: " << format_amount(a.get_balance()) << "\n";
		std::cout << "Choose an option:\n"
			"a - Add transaction\n"
			"l - List transactions\n"
			"s - Save transactions\n"
			"q - Save transactions and quit\n"
			"?: ";

		std::string command;
		std::getline(std::cin, command);
		if (command.empty())
			continue;

		switch (command[0]) {
		case 'a':
		{
			// add transaction to account
			// make sure it doesn't make account balance negative
			Transaction t = prompt_transaction();
			if (!a.add_transaction(t))
				std::cout << "Couldn't add transaction to account. Make sure balance doesn't fall into the negative.";
			break;
		}

		case 'l':
			// loop through all transactions in account
			for (const auto t : a)
			{
				std::cout << "On " << std::put_time(&t.timestamp, DATEFORMAT)
					<< ", " << t.recipient
					<< " received " << t.amount
					<< " for " << t.description << "\n";
			}
			break;

		case 's':
		case 'q':
		{
			// save file either way, then quit if q has been hit
			file.open(filename, std::fstream::out);
			if (!file.is_open())
			{
				std::cout << "Couldn't open output file " << filename << ". Instead streaming data here:\n";
				pipe_transactions(std::cout, a);
			}
			else
			{
				pipe_transactions(file, a);
				file.close();
			}

			if (command[0] == 'q')
				exit(0);
		}

		default:
			std::cout << "Unknown command " << command[0];
		}
	}
}