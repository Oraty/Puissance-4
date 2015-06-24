#include "Puissance4.h"
#include <iostream>
#include <stdexcept>
#include <string>
PuissanceQuatre::PuissanceQuatre(){
    for (auto& ligne : grille){  //for every line of "grille"
        for (auto& kase : ligne){// for every case of every line of "grille" //kase = case
            kase = vide;//set every case to "vide" (empty)
        }
    }
}

void PuissanceQuatre::print(){ // print 'O' for yellow and 'X' for red
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

 bool PuissanceQuatre::play(){
    std::cout << "Quelle est la couleur du premier joueur? (jaune ou rouge)" << std::endl;
    std::string joueur;
    std::cin >> joueur;
    try{
        if (joueur != "jaune" && joueur != "rouge"){
            throw std::invalid_argument("L'information rentrée n'est ni jaune ni rouge \n");
        }
    }
    catch (std::exception const& invArg){
    std::cout << invArg.what() ;
    return 0;
    }
    //ICI
    std::cout << "Sur quelle colonne jouer? (1-7)" << std::endl;
    unsigned int colonne{0};
    std::cin >> colonne;
    try{
        if (colonne < 0 || colonne > 7){
            throw std::invalid_argument("L'information rentrée n'est pas comprise entre 1 et 7 \n");
        }
    }
    catch (std::exception const& invArg){
    std::cout << invArg.what() ;
    return 0;
    }
    try{
        for (size_t i{0};grille[i][colonne] !=vide;++i){
            if (i>=7){
                throw std::out_of_range("La colonne est pleine!");
            }
        }
    }
    catch(std::exception const& __arg){
        std::cout << __arg.what();
        //Comment faire ici pour aller au point marqué "ICI" par un commentaire sans utiliser de goto?
    }


return 1;
}









