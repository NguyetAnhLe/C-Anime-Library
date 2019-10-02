#include "User.h"

int User::numUser = 0;

User::User(string id)
{
	accountID = id;
}


User::User()
{
	numUser++;
}
User:: ~User() {
	numUser--;
}
void User::accountType(bool noCode)const {
	if (noCode)
		cout << accountID << " is log in as User";
 }

