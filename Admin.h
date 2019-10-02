#pragma once
#ifndef ADMIN_H
#define ADMIN_H
#include "Account.h"
#include <stdio.h>

class Admin : public Account
{
private:
	const string adminPassCode = "Ot@kus'W0rld";
public:
	static const bool codeEnter = true;
	Admin();
	~Admin();
	string getPassCode() { return adminPassCode; }
	void checkAdminPassCode(string) const;
	void deleteUserAccount(string);
	void checkID(string, string);
	virtual void accountType(bool) const;
};
#endif
