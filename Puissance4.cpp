#include "Puissance4.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <typeinfo>

int getInt(){
  double num;

  std::cin >> num;  // This needs validation too.
  std::cin.ignore(80, '\n');
  while (num != static_cast<int>(num))
  {
    std::cout << "Désolé, ce n'est pas un nombre: ";
    std::cin >> num;
    std::cin.ignore(80, '\n');
  }
  std::cin.ignore(80, '\n');
  return static_cast<int>(num);
}

PuissanceQuatre::PuissanceQuatre(){
    for (auto& ligne : grille){  //for every line of "grille"
        for (auto& kase : ligne){// for every case of every line of "grille" //kase = case
            kase = vide;//set every case to "vide" (empty)
        }
    }
}

void PuissanceQuatre::print(){ // print 'O' for yellow and 'X' for red
    for (unsigned i{0};i<500;i++)
        std::cout << std::endl;

    for (auto ligne : grille){     //for every line of "grille"
        std::cout << " |";
        for (auto kase : ligne){  // for every case of every line of "grille" //kase = case
            if (kase == vide){
                std::cout << ' ';
            }
            else if(kase == jaune){
                std::cout << 'O';
            }
            else{
                std::cout << 'X';
            }
            std::cout << '|';
        }
        std::cout << std::endl;
    }
std::cout << '=';
for (unsigned i{1};i<=7;i++) std::cout << '=' << i;
std::cout << '=' << '=';
}

/*Play method *
 *vérifier si la grille est pleine dans ce cas terminer le jeu*
 *demander quel joueur joue en premier*
 *faire jouer ce joueur*
 *verifier son coup*
 *si le coup est invalide le faire jouer*
 */

Couleur PuissanceQuatre::askPlayerColor(){
    bool isJauneOrRouge;
    Couleur jeton;
    do{
        isJauneOrRouge = false;
        std::cout << "Quelle est la couleur du premier joueur? (jaune ou rouge)" << std::endl;
        std::string joueur;
        std::cin >> joueur;
        try{
            if (joueur != "jaune" && joueur != "rouge"){
                throw std::invalid_argument("L'information rentrée n'est ni jaune ni rouge \n");
            }else if (joueur == "jaune")jeton = jaune;
            else jeton = rouge;
        }
        catch (std::exception const& invArg){
        std::cout << invArg.what() ;
        isJauneOrRouge = true;
        }
    }while(isJauneOrRouge);
    return jeton;
}

unsigned int PuissanceQuatre::askPlayerColumn(){
    bool isArgValid;
    unsigned int colonne{0};
    do{
        isArgValid = false;
        std::cout << "Sur quelle colonne jouer? (1-7)" << std::endl;
        colonne = getInt();
        try{
            if (colonne <=0 || colonne > 7){
                throw std::invalid_argument("L'information rentrée n'est pas comprise entre 1 et 7 \n");
            }
        }
        catch (std::exception const& invArg){
            std::cout << invArg.what() ;
            isArgValid = true;
        }
        --colonne; // On fait correspondre le nombre entré avec l'index du tableau (0-6)
    }while(isArgValid);
    return colonne;
}


 void PuissanceQuatre::play(){
    auto jeton = PuissanceQuatre::askPlayerColor();
    decltype(jeton)& joueur{jeton};
    bool win;
    do{
    auto colonne = PuissanceQuatre::askPlayerColumn();
    int ligne{5};
    try{
        while (grille[ligne][colonne] !=vide){// on parcourt la colonne jusqu'a trouver une case vide
            if (ligne<=0){// Si la colonne est pleine, erreur.
                throw std::out_of_range("La colonne est pleine! \n");
            }
            else{
            --ligne;
            }
        }
    }
    catch(std::exception const& __arg){
        std::cout << __arg.what();
    }
    grille[ligne][colonne] = jeton;
    if (joueur != rouge)joueur = rouge;
    if (joueur != jaune)joueur = jaune;
    win = false;
    this->print();
    }while(!win);
}









