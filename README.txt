This program is to create an Anime database. It stores varities of anime and its information
Account can be created and use as user account or admin account. Passcode is required to log on as an admin
User is allow to bookmark the anime
Admin is allow to delete user account

Admin pass code is: Ot@kus'W0rld

•	Header files are  
	- Account.h
	- User.h
	- Admin.h
	- Anime.h 
	- AnimeDatabaseFunction.h

•	Classes and subclasses 
	- Account is a base class and has 2 subclass are User and Admin. 
	- Anime is a separate class

	o	Multiple constructors
		- Account.cpp line 5 and line 9
		- Anime.cpp line 5 and line 10
		- User.cpp line 5

	o	Destructor
		- User.cpp line 15

	o	Abstract Base class
		- Account class line 27

•	Inheritance / Polymorphism
	-Accoutn class for accountID and password variables

•	Pointers
	- Password verify functions in AnimeDatabaseFunction.cpp from line 61 to line 101

•	Static variables & functions
	- Anime.h line 17 and initialize at Anime.cpp line 4;  function called at main Final_AnimeDatabase.cpp at line 97
	- Admin.h line 12
	- User.h line 7 and 17

•	Exceptions
	- Empty class for exception in Account.h line 16
	- Throw exception in Account.cpp line 32 and line 37, in Admin.cpp at line 17 and line 31
	- Catch exception in main Final_AnimeDatabase.cpp at line 176, line 232, line 349, line 369, and line 432

•	Templates
	- Template swap function in AnimeDatabaseFuntion.cpp at line 404

•	Binary File I/O with random access
	- Read binary file in main Final_AnimeDatabase.cpp at line 142
	- Write binary file in main Final_AnimeDatabase.cpp at line 260

Extra
•	Virtual function or class
	- Account.h line 27
	- Admin.cpp at line 34; function call at main Final_AnimeDatabase.cpp at line 395
	- User.cpp at line 18; function call at main Final_AnimeDatabase.cpp at line 

•	Overloaded operators 
	- Overload == operator in Anime.cpp at line 46; used for findAnime function in AnimeDatabase.cpp at line 267

•	Recursion
	- Loop through vector Anime to store bookmarks in main Final_AnimeDatabase.cpp at line 324
	- Loop through vector Anime to display anime in AnimeDatabaseFunction.cpp from line 311 to 381