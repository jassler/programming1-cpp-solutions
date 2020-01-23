#include "transaction.h"

Transaction::Transaction()
	: timestamp({}), recipient(""), description(""), amount(0) {}

Transaction::Transaction(std::tm _timestamp, std::string _recipient, std::string _description, long _cents)
	: timestamp(_timestamp), recipient(_recipient), description(_description), amount(_cents) {}

std::string format_amount(long amount, char decimal_point, std::string currency)
{
	std::stringstream s;
	s << amount / 100 << decimal_point << amount % 100 / 10 << amount % 10 << currency;
	return s.str();
}
