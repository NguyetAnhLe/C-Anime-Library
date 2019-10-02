#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Account{
//supposed to be protected, bu for less complex programing, chnaged to public
public:
	string accountID;
	string password;
public:
	// empty class exception
	class Invalid {};
	Account();
	~Account();
	Account(string newAccountID);
	string setAccountID() const;
	string setPassword() const;
	void getAccount(string);
	void getPassword(string);
	void loadAccountID(string);
	//void loadPassword(string);
	void checkAccountID(string);
	virtual void accountType(bool)const = 0 ;

};

#endif // !ACCOUNT_H
