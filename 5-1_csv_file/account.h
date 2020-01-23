#ifndef H_ACCOUNT
#define H_ACCOUNT

#include "transaction.h"
#include <vector>

class Account
{
private:
	std::vector<Transaction> transactions;
	long balance = 0;

public:
	bool add_transaction(Transaction t);
	long get_balance();

	// begin and end to allow for-each loop through transactions array
	// -> for(auto transaction : account)
	auto begin() -> decltype(transactions.begin());
	auto end() -> decltype(transactions.end());
};

#endif
