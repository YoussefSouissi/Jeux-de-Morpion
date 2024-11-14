#pragma once
#include "Personne.h"

class Joueur : public Personne {
private:
	string symbole;
public:
	Joueur();
	void InitialiseSymbole();
	string getSymbole();
};

Joueur::Joueur() :Personne()
{
	InitialiseSymbole();
}

void Joueur::InitialiseSymbole()
{
    char symboleChoisi;
    bool symboleValide = false;

    while (!symboleValide) {
        cout << "   Choisissez votre symbole parmi les symboles suivants : * o x +" << endl;
        cout << "   Choix : ";
        cin >> symboleChoisi;

        if (symboleChoisi == '*' || symboleChoisi == 'o' || symboleChoisi == 'x' || symboleChoisi == '+') {
            this->symbole = symboleChoisi;
            symboleValide = true;
        }
        else {
            cout << "Symbole invalide !" << endl;
        }
    }
}

string Joueur::getSymbole()
{
    return this->symbole;
}