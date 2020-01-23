#include "account.h"

bool Account::add_transaction(Transaction t)
{
	if (balance + t.amount < 0)
		return false;

	transactions.push_back(t);
	balance += t.amount;
	return true;
}

long Account::get_balance()
{
	long sum = 0;
	for (auto t : transactions)
	{
		sum += t.amount;
	}

	return sum;
}

auto Account::begin() -> decltype(transactions.begin()) { return transactions.begin(); }
auto Account::end() -> decltype(transactions.end()) { return transactions.end(); }
