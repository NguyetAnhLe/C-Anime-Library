//This program is to create a anime database, which store anime information
// Account can be access as useror admin (if has passcode)
// user acc can store book mark 
// admin acc can delete user acc
//program allow registration at user and anime display base in user reference.

/*Pseudocode:
Account as a base class and has 2 subclass is user account and admin account
Account is in txt form that can store password and bookmark
also store user information in binary file and print out when user is logged in
Passcode for admin acc is const static variable that check in admin function
Anime txt file will be read and store in anime class vector
there will ve serveral switch statments for option menu 
Input validation will be about input string, char and number
capital letter wont be distinguish for ID name
Password will have some requirment using ptr to 
Will have some bool variable to check for login process
Seach anime through class vector has overloaded operator and iterator
*/


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include<iomanip>
#include "User.h"
#include "AnimeDataBaseFunction.h"
#include "Anime.h"
#include "Admin.h"
using namespace std;

void main() {
	// Variables declaration
	const int PRINT_LIST = 1,
		USER_LOGIN = 2,
		REGISTER = 3,
		SEARCH_N_BOOKMARK = 4,
		DISPLAY_BOOKMARK = 5,
		ADMIN_LOGIN = 6,
		LOG_OUT = 7,
		QUIT = 8,
		BY_ALPHABETICAL = 1,
		BY_RATING = 2,
		BY_YEAR = 3,
		RETURN = 4,
		DEL_USER_ACC = 1,
		AD_LOG_OUT = 2,
		AD_RETURN = 3,
		SIZE = 100;
	int choice, option, displayChoice, adminOption,
		upperCount = 0, lowerCount = 0, charCount = 0, digitCount = 0;/* symbolCount = 0*/
	double tempRating1, tempRating2;
	bool tryAgain = true, isLogin = false, isAdmin = false, dateReverse, nameReverse;
	char ch, yesNo, password1[SIZE], password2[SIZE];
	string tempID, tempPassword = "", reEnterPassword = "", passCode, bookMark, line, tempStr1, tempStr2;
	fstream binaryInforFile;
	ofstream account, output;
	ifstream input, login, getBookMark;
	Admin adminAccount;
	User userAccounts;
	vector<Anime> animeList;
	Anime tempData, anime;
	
	//Read data file
	//Open inputfile
	input.open("AnimeList.txt");
	if (input) {
		input.ignore(80, ']');
		//get data that separated by |
		while (getline(input, line)) {
			Anime        anime;
			string       field;
			stringstream ssFields;
			int fieldIndex = 0; // count for | section
			int i = 0;
			ssFields << line; // read the whole line first 
			while (getline(ssFields, field, '|')) {
				switch (fieldIndex) {
				case 0: anime.name = field;							 break;
				case 1: anime.type = field;							 break;
				case 2: anime.rating = field;						 break;
				case 3: anime.yearPublished = atoi(field.c_str());	 break;
				case 4: anime.number = atoi(field.c_str());			 break;
				case 5: anime.description = field;					 break;
				}
				fieldIndex++; // move to next section of |
			}
			//after read all the line, push back to vector anime
			animeList.push_back(anime);
		}
	}
	//done reading file
	input.close();
	//print how many anime read
	system("COLOR A0");
	// it show more than 2 anime might be cause it read some empty line at begin and end of file
	cout << "We have total " << Anime::numAnime - 2 << " animes here.\n";
	//start option menu
	while (true) {
		system("COLOR A0");
		printWelcomePage();
		cout << "\n\n Enter your choice: ";
		choice = getRangeNumber(1,8); //get option choice
		system("CLS");
		system("COLOR B0");
		switch (choice) {
		//OPTION 1 PRINT ANIME
		case PRINT_LIST:
			printListOption();
			cout << "Enter choice: ";
			option = getRangeNumber(1,4);
			system("CLS");
			//depends on what user refers, call the print anime option respectively
			system("COLOR F0");
					switch (option) {
					case BY_ALPHABETICAL:
						displayAnimeByName(animeList);
						pauseAndClearScr();
						break;
					case BY_RATING:
						displayAnimeByRating(animeList);
						pauseAndClearScr();
						break;

					case BY_YEAR:
						displayAnimeByYear(animeList);
						pauseAndClearScr();
						break;
					case RETURN:
						break;
					}
				break;

		// OPTION 2 USER LOGIN
		case USER_LOGIN:
			//checl of user already logged or not. to prevent multiple login
			if (isLogin) {
				cout << "You are already logged in as " << userAccounts.accountID << ".\n";
				
				//read user infor from binary file
				binaryInforFile.open(userAccounts.accountID + ".dat", ios::in | ios::binary);
				binaryInforFile.read(reinterpret_cast<char *>(&userAccounts.userInfo),sizeof(userAccounts.userInfo));
				//using template to swap depends on user preference
				if (nameReverse = true)
					swap(userAccounts.userInfo.firstName, userAccounts.userInfo.lastName);
				cout
					<< "Name: " << userAccounts.userInfo.firstName << " " << userAccounts.userInfo.lastName << endl;
				/*if (dateReverse = true)
				swap(userAccounts.userInfo.monthOfBirth, userAccounts.userInfo.dateOfBirth);*/

				//cout << userAccounts.userInfo.dateOfBirth << userAccounts.userInfo.monthOfBirth;
				cout << "Year of Birth: " << userAccounts.userInfo.yearOfBirth;
				binaryInforFile.close(); //Done ready file

				pauseAndClearScr();
			}

			//if user is not log in yet
			else {
				cout << "Please Enter you ID or enter R to return: ";
				cin >> userAccounts.accountID;
				//to return to main menu
				if (userAccounts.accountID == "R" || userAccounts.accountID == "r") {
					system("CLS");
					break;
				}

				//try-catch to block invalid id enter
				while (tryAgain) {
					try {
						userAccounts.loadAccountID(userAccounts.accountID);
						tryAgain = false; // to exit the loop

					}
					catch (Account::Invalid) {
						cout << "ID invalid. Please re-Enter your ID: ";
						cin >> userAccounts.accountID;
					}
				}
				tryAgain = true;
				//When valid id enter, means file can be open
				//get password form file that written between []
				login.open(userAccounts.accountID+".txt");
				login.ignore(80, '[');
				getline(login, userAccounts.password, ']');
				login.close();
				//done getting password
				//prompt user or their password
				cout << "Please enter your password: ";
				tempPassword = getpass(true); // get password hidden as *
				//If password is not valid, bring back to main menu
				// not allow retype password
				if (tempPassword != userAccounts.password) {
					cout << "Password invalid. I will bring you back to the main menu.\n";
					pauseAndClearScr();
					break;
				}
				//open user acccount file as an output to write their bookmark
				account.open(userAccounts.accountID + ".txt", ios::app);
				//call virtual function to sepaate account type;
				userAccounts.accountType(User::noCode);
				// turn bool login on
				isLogin = true;
				pauseAndClearScr();
			}
			break;
		case REGISTER:
			// Check if user are logging or not
			if (!isLogin) {
				cout << "Please choose your ID, or if you want to return, just enter 'R' : ";
				tempID = getNoSpace(); // No space is allowed as an ID for txt file
				cin.ignore(80, '\n');
				// for user if they want to return
				if (tempID == "r" || tempID == "R") {
					cout << "Gotcha! I will bring you back to the main menu.";
					pauseAndClearScr();
					break;
				}
				
				cout << "We are checking your ID...\n";
				Sleep(600); // pause a process for a while as if it is checking ID
				//Handle exception
				while (tryAgain) {
					try {
						//check if Id or file already exits
						userAccounts.checkAccountID(tempID);
						userAccounts.accountID = tempID; // if not exit, set account ID
						tryAgain = false; // to exit the loop

					}
					catch (Account::Invalid) {
						//print error and promt or ID again
						cout << "This ID already exited. Please enter another ID: ";
						tempID = getNoSpace();
						cout << "We are checking your ID...\n";
						Sleep(600);

					}
				}
				tryAgain = true;
				cout << "Please enter your choosen password: ";
				cin.getline(password1, 100); // not hidden as * for user to see
				cin.ignore();
				//Give some requirments then check it
				// Check whether if the password meed the requirement, if not continue to ask for the password
				while (!requirementCheck(upperCount, lowerCount, charCount, digitCount, /*symbolCount,*/ password1)/* || tempPassword != reEnterPassword*/) {
					// if not neet requirements, prompt again
					cout << "Please re-enter your choosen password: ";
					cin.getline(password1, 100);
				}
				// change  the array pass to string
				tempPassword = string(password1);
				//write password in there account file to check when login between []
				account.open(userAccounts.accountID + ".txt");
				userAccounts.password = tempPassword;
				account << "[" << userAccounts.password << "]\n";
				account.close();
				// For binary file, get some name and year of birth
				binaryInforFile.open(userAccounts.accountID + ".dat", ios::out | ios::binary);
				// get infomation of user
				cout << "What is your first name? ";
				cin.getline(userAccounts.userInfo.firstName, SIZE);

				cout << "What is your last name? ";
				cin.getline(userAccounts.userInfo.lastName, SIZE);

				//Can also ask for date and month but need more validation for month that has 30 or 31 or 29 days
				/*cout << "What month did you born in? ";
				cin >> userAccounts.userInfo.monthOfBirth;
				while (userAccounts.userInfo.monthOfBirth > 12 || userAccounts.userInfo.monthOfBirth < 0) {
					cout << "Are your sure? Please enter again: ";
					cin >> userAccounts.userInfo.monthOfBirth;
				}
				cout << "What date did you born in? ";
				cin >> userAccounts.userInfo.dateOfBirth;
				while (userAccounts.userInfo.dateOfBirth > 31 || userAccounts.userInfo.yearOfBirth < 0) {
					cout << "Are your sure? Please enter again: ";
					cin >> userAccounts.userInfo.dateOfBirth;
				}*/

				cout << "What year did you born in? ";
				cin >> userAccounts.userInfo.yearOfBirth;
				cin.ignore();
				//get most resonable age...
				while (userAccounts.userInfo.yearOfBirth > 2017 || userAccounts.userInfo.yearOfBirth < 1800) {
					cout << "I want a real human >.<. Please lemme know your true year of birth: ";
					cin >> userAccounts.userInfo.yearOfBirth;
				}
				// write in binary file;
				binaryInforFile.write(reinterpret_cast<char *>(&userAccounts.userInfo),sizeof(userAccounts.userInfo));
				binaryInforFile.close();

				/*cout << "How do your day of birth?\n 1> MM/DD/YYYY\n 2> DD/MM?YYYY\n Enter your choice: ";
				displayChoice = getRangeNumber(1, 2);
				if (displayChoice = 1)
					dateReverse = false;
				else dateReverse = true;*/
				
				//Ask for user reference, how they want their name to be displayed
				cout << "How do your day of name\n 1> FirstName LastName\n 2> LastName \FirstName\n Enter your choice: ";
				displayChoice = getRangeNumber(1, 2);
				if (displayChoice = 1)
					nameReverse = false;
				else nameReverse = true;

				cout << "You have sucessfully created an account! Please go back and Log in.\n";
				pauseAndClearScr();
				break;
			}
			
			//If user is logged in
			cout << "Please log out first!";
			pauseAndClearScr();
			break;

		// FOR SEARCH AND BOOKMARK
		case SEARCH_N_BOOKMARK:
			//Call searching function
			findAnime(animeList, isLogin);
			// Only for user logged in 
			// write their bookmark anime to their account file and store
			if (isLogin) {
				for (int i = 0; i < animeList.size(); i++) {
					if (animeList[i].bookmark == true) {
						account << "Name: " << animeList[i].name << " | " << animeList[i].type << endl;
						animeList[i].bookmark = false; // return bookmark bool 
					}
				}
				cout << "Gotcha! Press any key to return";
				pauseAndClearScr();
				break;
			}
			pauseAndClearScr();
			break;

		// ADMIN LOGIN AND OPTION
		case ADMIN_LOGIN:
			// Cannot log in as admin while already login as user/ another admin
			if (!isLogin) {
				if (!isAdmin) {
					// get passcode to login as admin
					cout << "Access limited. Please enter Admin Pass Code: ";
					passCode = getpass(true); // hidden passcode
					Sleep(300);
					// handle invalid passcode
					try {
						adminAccount.checkAdminPassCode(passCode);
						cout << "Valid Code!";
					}
					catch (Account::Invalid) {
						cout
							<< "Sorry, permission cannot be granted!\n"
							<< "I will get you back to the main menu.";
						_getch();
						system("CLS");
						break;
					}
					//When valid passcode, get ID and password
					cout << "Please enter your ADMIN ID: ";
					cin >> adminAccount.accountID;
					cout << "Please enter your password: ";
					tempPassword = getpass(true); // hidden password
					
					//Not allow to know if their ID ot password was wrong
					// so check it after get eveything from user
					// handle wrong ID
					try {
						adminAccount.loadAccountID(adminAccount.accountID);
					}
					catch (Account::Invalid) {
						cout
							<< "No Access cannot be granted.\n"
							<< "Sorry but I will need to bring you back to main menu...";
						_getch();
						system("CLS");
						break;
					}
					//If ID valid, get password and check
					login.open(adminAccount.accountID + ".txt");
					login.ignore(80, '[');
					getline(login, adminAccount.password, ']');
					login.close();
					if (tempPassword != adminAccount.password) {
						cout
							<< "Access cannot be granted.\n"
							<< "Sorry but I will need to bring you back to main menu...";
						_getch();
						system("CLS");
						break;
					}

					// IF both ID and password is valid, acces granted
					Sleep(300);
					cout << "Access Granted....\n";
					// to separate ypr account
					adminAccount.accountType(Admin::codeEnter);
					isAdmin = true; // turn on log in bool
					pauseAndClearScr();
				}
					
				// Display admin option
				// would have add and delete anime
				system("COLOR D0");
					printAdminMenu();
					cout << "Please enter yout option choice: ";
					adminOption = getRangeNumber(1, 3);
					// perform for each option
						switch (adminOption) {
						case DEL_USER_ACC:
							// get user account
							cout << "Please enter the Account ID that you want to delete: (or hit R to go back to the main menu)";
							tempID = getString();
							// to return option
							if (tempID == "R" || tempID == "r") {
								system("CLS");
								break;
							}
							
							// Handle exception
							while (tryAgain) {
								try {
									// check if account is not the account that is logged in
									adminAccount.checkID(tempID, adminAccount.accountID);
									// check if that accoutn is exits
									userAccounts.loadAccountID(tempID);
									// get the user account ID when done checking
									userAccounts.accountID = tempID;

									tryAgain = false; // to exit the loop

								}
								//pritn error, prompt for id again
								catch (Account::Invalid) {
									cout << "ID invalid. Please re-Enter the ID: ";
									tempID = getString();
								}
							}
							tryAgain = true;
							cout << "are you sure that you want to delete this account <" << userAccounts.accountID << ">? (Y/N) ";
							yesNo = getTwoLetterRange('Y','N');
							if (toupper(yesNo) == 'Y') {
								// call delete fucntion
								adminAccount.deleteUserAccount(userAccounts.accountID);
								pauseAndClearScr();
							}
							else {
								cout << "Okey, I will get you back to the main menu!";
								pauseAndClearScr();
							}
							break;
					
						case AD_LOG_OUT:
							cout << "Do you want to log out ? (Y/N)";
							yesNo = getTwoLetterRange('Y', 'N');
							if (toupper(yesNo) == 'Y') {
								isAdmin = false; // turn of the log in bool
								cout << "You are logged out.";
								pauseAndClearScr();
								break;
							}
							else {
								cout << "Okey! I will take you back to the main menu....";
								pauseAndClearScr();
								break;
							}
							break;
						case AD_RETURN:
							system("CLS");
							break;
						}
				break;
			}

			// print error if is logged 
			cout << "Please log out from another account first.";
			pauseAndClearScr();
			break;

		// DISPLAY USER BOOK MARK;
		case DISPLAY_BOOKMARK:
			// only for logged in user
			if (isLogin) {
				//get bookMark from inout account file
				// read file , no file input validation because already checked whne login
				getBookMark.open(userAccounts.accountID + ".txt");
				getBookMark.ignore(80, ']');
				//display while reading
				system("COLOR F0");
				while 	(getline(getBookMark,bookMark)){
					cout << bookMark << "\n";
				}
				getBookMark.close();
				pauseAndClearScr();
				break;
			}
			//print error of not logged in
			cout << "Please log in or register to use this option";
			pauseAndClearScr();
			break;

		// USER LOG OUT
		case LOG_OUT:
			if (isLogin && !isAdmin) {
				cout << "Do you want to log out?";
				yesNo = getTwoLetterRange('Y', 'N');
				if (yesNo == 'y' || yesNo == 'Y') {
					account.close();
					cout << "You are logged out.\n";
					isLogin = false; // turn off bool log in
					pauseAndClearScr();
					break;
				}
				else {
					cout << " Okey, I will get you back to you main menu";
					pauseAndClearScr();
					break;
				}
			}
			//check if is in admin log in
			if (isAdmin) {
				cout << "Please log out your ADMIN account in Admin option.";
				pauseAndClearScr();
				break;
			}

			//print error
			cout << "You are not logged in. :(\n";
			pauseAndClearScr();
			break;

		// TO QUIT PROGRAM
		case QUIT:
			cout << "Thanks for using. Terminating program...";
			pauseAndClearScr();
			exit(0);
			break;

				}
			}
		}
	