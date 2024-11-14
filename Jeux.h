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
    void DisplayGridGame();
    void InitialisePlayer();
    void GamePlay();
    bool checkWin();
    bool isGridFull();
    
};
Jeux::Jeux() {
    InitialisePlayer();
    createGrid();
    GamePlay();
}
void Jeux::createGrid()
{
    int valeur = 1;
    for (int i = 0; i < taille_grid; i++) {
        for (int j = 0; j < taille_grid; j++) {
            matrix[i][j] = valeur++;
        }
    }
}




void Jeux::InitialisePlayer() {
    for (int i = 0; i < 2; i++) {
        cout << "Joueur " << i + 1 << " :" << endl;
        Joueur joueur; 
        this->players.push_back(joueur);
    }
}




void Jeux::DisplayGridGame() {
    for (int i = 0; i < taille_grid; i++) {
        for (int j = 0; j < taille_grid; j++) {
            if (matrix[i][j] == -1) {
                cout << " " << players[0].getSymbole() << " ";
            }
            else if (matrix[i][j] == -2) {
                cout << " " << players[1].getSymbole() << " ";
            }
            else {
                cout << " " << matrix[i][j] << " ";
            }

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


void Jeux::GamePlay() {
   
    int turn = 0;
    while (!checkWin() && !isGridFull()) {
        int move;
        string currentPlayerName = players[turn % 2].getName();
        string currentPlayerSymbol = players[turn % 2].getSymbole();

        cout << "Tour de " << currentPlayerName << ", Choisissez une position pour placer votre symbole : "<<endl;
        DisplayGridGame();


        bool validMove = false; 

        
        while (!validMove) {
            cout <<endl << "Choix : ";
            cin >> move;

            
            for (int i = 0; i < taille_grid; i++) {
                for (int j = 0; j < taille_grid; j++) {
                    if (matrix[i][j] == move) {
                        matrix[i][j] = (turn % 2 == 0) ? -1 : -2;  
                        validMove = true;
                        break;
                    }
                }
                if (validMove) break;
            }

            if (!validMove) {
                cout << "Mouvement invalide. Veuillez choisir une position vide." << endl;
            }
        }

        turn++;
    }

    DisplayGridGame();

    if (checkWin()) {
        cout << "Joueur " << (turn % 2 == 0 ? players[1].getName() : players[0].getName()) << " a gagne !" << endl;
    }
    else if (isGridFull()) {
        cout << "Match nul !" << endl;
    }
}

bool Jeux::checkWin() {
    for (int i = 0; i < taille_grid; i++) {
        if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2] && matrix[i][0] != 0) {
            return true;  
        }
    }
    for (int i = 0; i < taille_grid; i++) {
        if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i] && matrix[0][i] != 0) {
            return true;  
        }
    }

    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[0][0] != 0) {
        return true;  
    }
    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0] && matrix[0][2] != 0) {
        return true; 
    }

    return false;
}

bool Jeux::isGridFull() {
    for (int i = 0; i < taille_grid; i++) {
        for (int j = 0; j < taille_grid; j++) {
            if (matrix[i][j] != -1 && matrix[i][j] != -2) {  
                return false;
            }
        }
    }
    return true;
}


