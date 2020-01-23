#ifndef H_TRANSACTION
#define H_TRANSACTION

#include <sstream>
#include <string>
#include <ctime>

struct Transaction
{
	std::tm timestamp;
	std::string recipient;
	std::string description;
	long amount;

	Transaction();
	Transaction(std::tm _timestamp, std::string _recipient, std::string _description, long _cents);
};

std::string format_amount(long amount, char decimal_point = '.', std::string currency = "");

#endif
