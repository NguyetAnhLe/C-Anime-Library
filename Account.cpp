#include "Account.h"



Account::Account(string newAccountID)
{
	accountID = newAccountID;
}
Account::Account() {

}

Account::~Account() {

}

string Account::setAccountID() const {
	return accountID;
}
string Account::setPassword() const {
	return password;
}
void Account::getAccount(string id) {
	accountID = id;
}
void Account::getPassword(string pass) {
	password = pass;
}
void Account::checkAccountID(string id) {
	ifstream in(id+".txt");
	if (in)
		throw Invalid();
}
void Account::loadAccountID(string enteredName) {
	ifstream in(enteredName+".txt");
	if (!in)
		throw Invalid();
}
//void Account::loadPassword(string enteredPassword) {
//	if (password != enteredPassword)
//		throw Invalid();
//}