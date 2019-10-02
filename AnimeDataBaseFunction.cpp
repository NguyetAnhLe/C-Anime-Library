#include "AnimeDataBaseFunction.h"


void printWelcomePage() {
	cout
		<< "\n\n\n"
		<< "    **********************************************************************************\n"
		<< "    *                        WELCOME TO MOLI'S ANIME DATABASE                        *\n"
		<< "    *                                                                                *\n"
		<< "    *  Please chose option to perform                                                *\n"
		<< "    *           [1] Display Anime List                                               *\n"
		<< "    *           [2] User Login                                                       *\n"
		<< "    *           [3] User Register                                                    *\n"
		<< "    *           [4] Search & Bookmark                                                *\n"
		<< "    *           [5] Display Bookmark                                                 *\n"
		<< "    *           [6] Admin Login                                                      *\n"
		<< "    *           [7] Logout                                                           *\n"
		<< "    *           [8] Quit                                                             *\n"
		<< "    *                                                                                *\n"
		<< "    **********************************************************************************\n";
}
void printListOption() {
	cout
		<< "\n\n\n"
		<< "    **********************************************************************************\n"
		<< "    *                                                                                *\n"
		<< "    *  Please chose option to perform                                                *\n"
		<< "    *           [1] By Alphabetical                                                  *\n"
		<< "    *           [2] By Rating                                                        *\n"
		<< "    *           [3] By Year                                                          *\n"
		<< "    *           [4] Return                                                           *\n"
		<< "    *                                                                                *\n"
		<< "    **********************************************************************************\n";
}
void printAdminMenu() {
	cout
		<< "\n\n\n"
		<< "    **********************************************************************************\n"
		<< "    *                                                                                *\n"
		<< "    *  Please chose option to perform                                                *\n"
		<< "    *           [1] Delete User Account                                              *\n"
		<< "    *           [2] Logout                                                           *\n"
		<< "    *           [3] Return                                                           *\n"
		<< "    *                                                                                *\n"
		<< "    **********************************************************************************\n";
}
void printUserMenu() {
	cout
		<< "\n\n\n"
		<< "    **********************************************************************************\n"
		<< "    *                                                                                *\n"
		<< "    *  Please chose option to perform                                                *\n"
		<< "    *           [1] Show Bookmark                                                    *\n"
		<< "    *           [2] Change password                                                  *\n"
		<< "    *           [5] Return                                                           *\n"
		<< "    *                                                                                *\n"
		<< "    **********************************************************************************\n";
}

//count for the digit in the password
int countForDigit(char*ptr) {
	int digit = 0;
	while (*ptr != '\0') {
		if (isdigit(*ptr))			 // check for number
			digit++;
		*ptr++;			// move to the next char
	}
	return digit;
}

// Count for how many letter in the password
int  countTotalChar(char*ptr) {
	int count = 0;				// First try count =1, it countmore than 1 letters -> so count should be 0;
								//Loop through what user enter
	while (*ptr != '\0') {
		count++;			// count for total character
		*ptr++;
	}
	return count;
}

// count for how many uppercase
int countForUppercase(char*ptr) {
	int upper = 0;
	while (*ptr != '\0') {
		if (isupper(*ptr))		 // check for upper case
			upper++;
		*ptr++;
	}
	return upper;
}

//count for how many lower case
int countForLowercase(char*ptr) {
	int lower = 0;
	while (*ptr != '\0') {
		if (islower(*ptr))		// check for lower case
			lower++;
		*ptr++;
	}
	return lower;

}

//Check all the requirements
bool requirementCheck(int upper, int lower, int count, int digit, /*int symbol,*/ char*ptr) {
	const int MIN_CHAR = 6;
	//symbol = countSpecialChar(ptr);
	digit = countForDigit(ptr);
	upper = countForUppercase(ptr),
	lower = countForLowercase(ptr);
	count = countTotalChar(ptr);

	if (count >= MIN_CHAR && upper >= 1 && lower >= 1 && digit >= 1 /*&& symbol == 1*/)		// is true if all the requirements meet
		return true;

	else {
		cout << "\n\t*****You are missing requirements******\n";

		// pritn out the things that didnt meet.
		if (count < MIN_CHAR)
			cout << " - Your password need at leats " << MIN_CHAR << " letters\n";		// it should be printed if the password is less than 6 letters
		if (upper < 1)
			cout << " - You need at least 1 upper case letter\n";		// should be printed if nas no capital letter
		if (lower < 1)
			cout << " - You need at least 1 lower case letter\n";		// should be printed out if the password is all capitaled
		if (digit < 1)
			cout << " - You need at least 1 digit\n";					// should be printed out if has no number
		//if (symbol != 1)
		//	cout
		//	<< " - Your password should contain ONE of the following characters: ! @ # $ %"
		//	<< " but no other special characters.\n"; // should be printed out if has none or more than 1 character of !@#$%
		//											  // try Anhle@!#$$##  => should print out in approriate password.

		return false;
	}
}

//get pass as an *
string getpass(bool show_asterisk = true)
{
	const char BACKSPACE = 8;
	const char RETURN = 13;

	string password;
	unsigned char ch = 0;

	while ((ch = _getch()) != RETURN)
	{
		if (ch == BACKSPACE)
		{
			if (password.length() != 0)
			{
				if (show_asterisk)
					cout << "\b \b";
				password.resize(password.length() - 1);
			}
		}
		else if (ch == 0 || ch == 224) // handle escape sequences
		{
			_getch(); // ignore non printable chars
			continue;
		}
		else
		{
			password += ch;
			if (show_asterisk)
				cout << '*';
		}
	}
	cout << endl;
	return password;
}

string getString() {
	char str[100];
	cin >> ws;
	cin.get(str, 100);
	return str;
}
//Take only letters that are before the space
string getNoSpace() {
	string str = getString();
	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
			str.erase(i, 1); // erase the space / 1 char
			i--; // put back 1 char
		}
	}
	return str;
}

char getChar() {
	char ch;
	cin >> ch; cin.ignore(100, '\n');
	return ch;
}

char getLetter() {
	char letter;
	letter = getChar();
	while (letter < 'A' || letter > 'Z' && letter < 'a' || letter >'z') {
		cout << "\t" << letter << " is NOT a letter. Try again: ";
		letter = getChar();
	}
	return letter;
}

char getTwoLetterRange(char a, char b) {
	char letter;
	letter = getLetter();
	while (letter != a  && letter != tolower(a) && letter != b && letter != tolower(b)) {
		cout << "\tPlease choose between \"" << a << "\" and \"" << b << "\". Please try again: ";
		letter = getLetter();
	}
	return letter;
}

double getDouble() {
	double number;
	number = getNumber();
	return number;
}

double getPositiveNumber() {
	double number;
	number = getDouble();
	while (number < 0) {
		cout << "\tPlease give a positive number: ";
		number = getDouble();
	}
	return number;
}

double getWholePositiveNumber() {
	double number;
	number = getPositiveNumber();
	while (number != (int)number) {
		cout << "\tPlease give a whole number: ";
		number = getPositiveNumber();
	}
	return number;
}

double getNumber() {
	double number;
	while (!(cin >> number)) {
		cin.clear(); cin.ignore(10000, '\n');
		cout << "\tNo letter please. Try again: ";
	}
	cin.ignore(80, '\n');
	return number;
}

double getRangeNumber(int min, int max) {
	double number;
	number = getWholePositiveNumber();
	while (number < min || number > max) {
		cout << "\tPlease enter choice from " << min << " to " << max << ". Try again: ";
		number = getWholePositiveNumber();
	}
	return number;
}

// find anime in vector Anime class
// using iterator
void findAnime(vector<Anime> &animeList, bool isLogin) {
	vector<Anime>::iterator it;
	it = animeList.begin();
	int count = 0; // get the position
	// get for name
	cout << "Enter the Anime name: ";
	string input;
	input = getUpperFirstChar();
	// infinite loop 
	for (;;) {
		if (it->name == input) {
			//cout << "found it at " << count;
			break; // when found break the loop
		}
		else {
			*it++;
			count++; 
		}
		if (it == animeList.end()) break;
	}
	// print out what found
	if (it != animeList.end()) {
		cout
			<< "Anime: " << it->name << "  -  " << it->type << endl
			<< "Number of Episode: " << it->number << endl
			<< "Year Published: " << it->yearPublished << endl
			<< "Summary: " << it->description << endl
			<< "\n*****************************************************\n";

		// allow bookmark option if login as user
		if (isLogin) {
			cout << "Do you want to bookmark it? (Y/N)";
			char yesNo = getTwoLetterRange('Y', 'N');
			if (toupper(yesNo) == 'Y') 
				it->bookmark = true;
			}
		}
	else
			cout << "Anime cannot be found \n";

}

//display by alphabetical
void displayAnimeByName(vector<Anime>& animeList) {
	Anime tempData;
	for (int i = 0; i < animeList.size(); i++) {
		tempData = animeList[i];
		for (int k = i + 1; k < animeList.size(); k++) {
			if (tempData.name > animeList[k].name) {
				animeList[i] = animeList[k];
				animeList[k] = tempData;
				tempData = animeList[i];
			}
		}
	}
	for (int i = 0; i <animeList.size(); i++) {
		cout << left << setw(70) << animeList[i].name << setw(30)
			<< animeList[i].type << setw(10)
			<< animeList[i].rating << "\n";
	}
}

// display by rating
void displayAnimeByRating(vector<Anime>& animeList) {
	Anime tempData;
	string tempStr1, tempStr2;
	double tempRating1, tempRating2;
	for (int i = 0; i < animeList.size(); i++) {
		tempData = animeList[i];
		for (int k = i + 1; k < animeList.size(); k++) {
			tempStr1 = tempData.rating;
			tempStr2 = animeList[k].rating;
			if (tempStr1 == "N/A") {
				tempStr1 = "0.0";
			}
			if (tempStr2 == "N/A") {
				tempStr2 = "0.0";
			}

			tempRating1 = atof(tempStr1.c_str());
			tempRating2 = atof(tempStr2.c_str());
			if (tempRating1 < tempRating2) {
				animeList[i] = animeList[k];
				animeList[k] = tempData;
				tempData = animeList[i];
			}
		}
	}
	for (int i = 0; i <animeList.size(); i++) {
		cout << left << setw(70) << animeList[i].name << setw(30)
			<< animeList[i].type << setw(10)
			<< animeList[i].rating << "\n";
	}


}

// display by year published
void displayAnimeByYear(vector<Anime>&animeList) {
	Anime tempData;
	for (int i = 0; i < animeList.size(); i++) {
		tempData = animeList[i];
		for (int k = i + 1; k < animeList.size(); k++) {
			if (tempData.yearPublished < animeList[k].yearPublished) {
				animeList[i] = animeList[k];
				animeList[k] = tempData;
				tempData = animeList[i];
			}
		}
	}
	for (int i = 0; i <animeList.size(); i++) {
		cout << left << setw(70) << animeList[i].name << setw(30)
			<< animeList[i].type << setw(10)
			<< animeList[i].rating << "\n";
	}


}

// stop and clear screen
void pauseAndClearScr() {
	_getch();
	system("CLS");
}

string getUpperFirstChar() {
	string str = getString();
	str[0] = toupper(str[0]);
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ')
			str[i + 1] = toupper(str[i + 1]);
	}
	return str;
}

// for swaping display as user reference 
template <class T>
void swap(T &var1, T &var2) {
	T temp;
	temp = var1;
	var1 = var2;
	var2 = temp;
}