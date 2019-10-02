#pragma once
#ifndef ANIME_H
#define ANIME_H
#include <iostream>
#include "string"
using namespace std;
class Anime{
public:
	string name;
	string type;
	string description;
	int yearPublished;
	string rating; // no more than 10 and no less than 0
	int number;	bool bookmark;
	//overloaded operator ==
	bool Anime::operator == (const Anime &right);
	static int numAnime;
public:
	//virtual double getDuration() = 0;
	Anime();
	~Anime();
	Anime(string, string, string, string, int, int);
	string setName();
	string setType();
	string setDescription();
	int setYearPublish();
	string setRating();
	int setNumber();
	void printAnime();

};

#endif // !ANIME_H