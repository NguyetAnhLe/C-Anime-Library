#pragma once
#ifndef USER_H
#define USER_H
#include "Account.h"
class User : public Account{
public:
	static const int SIZE = 100;
	struct Info {
		char lastName[SIZE];
		char firstName[SIZE];
		//int dateOfBirth;
		//int monthOfBirth;
		int yearOfBirth;
	};
	Info userInfo;
	static int numUser;
	static const bool noCode = true;
public:
	User(string);
	User();
	~User();
	virtual void accountType(bool) const;
};
#endif

