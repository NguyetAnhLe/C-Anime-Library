#include "Admin.h"



Admin::Admin()
{
	
}


Admin::~Admin()
{
}

void Admin::checkAdminPassCode(string enteredCode) const {
	if (enteredCode != adminPassCode)
		throw Invalid();
}

void Admin::deleteUserAccount(string userAccountID) {
	string deleteAcountID = userAccountID + ".txt";
	if (remove(deleteAcountID.c_str()) != 0)
		perror("Error deleting Account... Please Try Again.");
	else
		puts("Account successfully deleted!");
}
void Admin::checkID(string enteredID, string currentLoginID) {
	enteredID[0]=tolower(enteredID[0]);
	currentLoginID[0]=tolower(currentLoginID[0]);
	if (currentLoginID == enteredID)
		throw Invalid();
}

void Admin::accountType(bool codeEnter) const{
	if (codeEnter)
		cout << accountID << " is now log in as Admin";

}