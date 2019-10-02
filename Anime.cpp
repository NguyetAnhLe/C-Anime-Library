#include "Anime.h"


int Anime::numAnime = 0;
Anime::Anime()
{
	numAnime++;

}
Anime::Anime(string name,string despcription, string type, string rating, int number, int yearPublished)
{
	this->name = name;
	this->description = description;
	this->type = type;
	this->rating = rating;
	this->number = number;
	this->yearPublished = yearPublished;
	numAnime++;
}

Anime::~Anime()
{
	//numAnime--;
}
string Anime::setName() {
	return name;
}
string Anime::setDescription() {
	return description;
}
string Anime::setType() {
	return type;
}
int Anime::setYearPublish() {
	return yearPublished;
}
string Anime::setRating() {
	return rating;
}
int Anime::setNumber() {
	return number;
}
//double Anime::getDuration(){
//	return duration;
//}
bool Anime::operator == (const Anime &right) {
	bool status;
	if (name == right.name)
		status = true;
	else
		status = false;
	return status;
}
void Anime:: printAnime() {
	cout << "There are " << numAnime << "animes displayed.";
}