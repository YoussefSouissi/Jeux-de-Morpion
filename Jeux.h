#pragma once
#include "Joueur.h"
#include <iostream>
#include <vector>

using namespace std;
class Jeux {
private:
    static const int taille_grid = 3;  
    int matrix[taille_grid][taille_grid];
    string choix;
    vector<Joueur> players;
public:
    Jeux();
    void createGrid();
    void InitialisePlayer();
};

void Jeux::createGrid()
{
    int valeur = 1;
    for (int i = 0; i < taille_grid; i++) {
        for (int j = 0; j < taille_grid; j++) {
            matrix[i][j] = valeur++;
        }
    }

    for (int i = 0; i < taille_grid; i++) {
        
        for (int j = 0; j < taille_grid; j++) {
            cout << " " << matrix[i][j] << " ";
            if (j < taille_grid - 1) cout << "|";
        }
        cout << endl;
        
        if (i < taille_grid - 1) {
            cout << "------------";
            cout << endl;
        }
    }
    cout << endl;
}

Jeux::Jeux(){
    InitialisePlayer();
}


void Jeux::InitialisePlayer() {
    for (int i = 0; i < 2; i++) {
        cout << "Joueur " << i + 1 << " :" << endl;
        Joueur joueur; 
        this->players.push_back(joueur);
    }
}
