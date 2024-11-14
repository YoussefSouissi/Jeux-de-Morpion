#pragma once
#include<iostream>
using namespace std;

class Personne {
protected:
	string nom;
	string prenom;
public:
	Personne();
	void InitialisePlayer();
	string getName();
	string getSurname();
};

Personne::Personne()
{
	InitialisePlayer();
}

void Personne::InitialisePlayer()
{
	cout << "   Entrez votre nom :  ";
	cin >> this->nom;
	cout << "   Entrez votre prenom  : ";
	cin >> this->prenom;

}

string Personne::getName()
{
	return this->nom;
}
string Personne::getSurname()
{
	return this->prenom;
}
