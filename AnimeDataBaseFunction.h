#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <conio.h>
#include <sstream>
#include <cstring>
#include "Anime.h"
#include <algorithm>
#include <conio.h>
#include <time.h>
#include <Windows.h>

using namespace std;

//int readData(string[],ifstream &inputFile);
//void print(string[], int , ostream &os=cout);
//void getAnime(int n, string [], Anime *);
void printWelcomePage();
void printListOption();
void printAdminMenu();
void printUserMenu();
//template<class T>
//void searchAnime(string input, vector<Anime>& );
//Anime* loadList(ifstream &input);

//int countSpecialChar(char*);
int countTotalChar(char*);
int countForUppercase(char*);
int countForLowercase(char*);
int countForDigit(char*);
bool requirementCheck(int, int, int, int,/* int,*/ char*);
string getpass(bool);
string getNoSpace();
string getString();
char getChar();
char getLetter();
char getTwoLetterRange(char a, char b);
double getRangeNumber(int min, int max);
double getDouble();
double getPositiveNumber();
double getWholePositiveNumber();
double getNumber();
void findAnime(vector<Anime>&, bool);
void displayAnimeByName(vector<Anime>&);
void displayAnimeByRating(vector<Anime>&);
void displayAnimeByYear(vector<Anime>&);
void pauseAndClearScr();
string getUpperFirstChar();
template <class T>
void swap(T &var1, T &var2);