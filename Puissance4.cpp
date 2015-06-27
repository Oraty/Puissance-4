#include "Puissance4.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <limits>

bool getUInt(unsigned int& i)
{
    while (!(std::cin >> i))
    {
        if (std::cin.eof())
        {
            return false;
        }
        else if ( std::cin.fail() )
        {
            std::cout << "Saisie incorrecte, recommencez : ";
            std::cin.clear();
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
        }
    }
    return true;
}

PuissanceQuatre::PuissanceQuatre()
{
    for (auto& colonne : grille)   //for every column of "grille"
    {
        for (auto& kase : colonne) // for every case of every comumn of "grille" //kase = case
        {
            kase = vide;//set every case to "vide" (empty)
        }
    }
}

void PuissanceQuatre::print()  // print 'O' for yellow and 'X' for red
{
    for (unsigned i {0}; i<500; i++)
        std::cout << std::endl;

    for (auto ligne : grille)      //for every column of "grille"
    {
        std::cout << " |";
        for (auto kase : ligne)   // for every case of every column of "grille" //kase = case
        {
            if (kase == vide)
            {
                std::cout << ' ';
            }
            else if(kase == jaune)
            {
                std::cout << 'O';
            }
            else
            {
                std::cout << 'X';
            }
            std::cout << '|';
        }
        std::cout << std::endl;
    }
    std::cout << '=';
    for (unsigned i {1}; i<=7; i++) std::cout << '=' << i;
    std::cout << '=' << '=';
}

/*Play method *
 *vérifier si la grille est pleine dans ce cas terminer le jeu*
 *demander quel joueur joue en premier*
 *faire jouer ce joueur*
 *verifier son coup*
 *si le coup est invalide le faire jouer*
 */

Couleur PuissanceQuatre::askPlayerColor()
{
    Couleur jeton;
    std::cout << "Quelle est la couleur du premier joueur? (jaune ou rouge)" << std::endl;
    std::string joueur;
    std::cin >> joueur;
    if (std::cin.eof())
    {
        return vide;
    }
    while (joueur != "jaune" && joueur != "rouge")
    {
        std::cout << "Veuillez rentrer une information comprise entre \" jaune \" et \" rouge \" \n";
        std::cin >> joueur;
        if (std::cin.eof())
        {
            return vide;
        }
    }
    if (joueur == "jaune")jeton = jaune;
    else jeton = rouge;
    return jeton;
}

unsigned int PuissanceQuatre::askPlayerColumn()
{
    unsigned int colonne {0};
    std::cout << "Sur quelle colonne jouer? (1-7)" << std::endl;
    auto isNotQuited = getUInt(colonne);
    if (colonne <= 0 || colonne > 7)
    {
        std::cout << "Veuillez entrer un chiffre entier compris entre 1 et 7 inclus\n";
        isNotQuited = getUInt(colonne);
    }
    if (!isNotQuited)
    {
        return 10;
    }
    --colonne; // On fait correspondre le nombre entré avec l'index du tableau (0-6)
    return colonne;
}

unsigned int PuissanceQuatre::countTokens(int dir_colonne,int dir_ligne,std::size_t ligne,std::size_t colonne)
{
    int i {0};
    Couleur jeton = grille[ligne][colonne];
    if (jeton == vide)
    {
        return 1;
    }
    while(ligne < grille.size() &&
            colonne < grille[ligne].size() &&
            grille[ligne][colonne] == jeton)
    {
        ligne += dir_ligne;
        colonne += dir_colonne;
        i++;
    }
    return i;
}

bool PuissanceQuatre::isWon(Couleur joueur)
{
    for(std::size_t ligne {5}; ligne < grille.size(); ligne--)
    {
        for(std::size_t colonne {0}; colonne < grille[ligne].size(); colonne++)
        {
            if (grille[ligne][colonne] == joueur)
            {
                if (PuissanceQuatre::countTokens(-1,0,ligne,colonne) >= 4 ||
                        PuissanceQuatre::countTokens(-1,+1,ligne,colonne) >= 4 ||
                        PuissanceQuatre::countTokens(0,1,ligne,colonne) >= 4 ||
                        PuissanceQuatre::countTokens(+1,-1,ligne,colonne) >= 4)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
bool PuissanceQuatre::isGrillePleine()
{
    unsigned int i {0};
    while(grille[0][i] != vide)
    {
        i++;
    }
    if (i >= 7)
    {
        return true;
    }
    return false;
}
void PuissanceQuatre::play()
{
    auto joueur = this->askPlayerColor(); //Jeton = couleur choisie par le joueur
    decltype(joueur)& jeton {joueur}; //Création d'une référence à joueur pour la sémantique
    if (jeton == vide)//Si le joueur à quité.
    {
        return;
    }
    bool isWon {};
    do //Déroulement du jeu
    {
        if(isGrillePleine())
        {
            std::cout << "\n La grille est pleine!" << std::endl;
            return;
        }
        int ligne {5};
        auto colonne = this->askPlayerColumn();
        while (grille[ligne][colonne] != vide)// on parcourt la colonne de haut en bas jusqu'a trouver une case vide
        {
            ligne--;
            if (ligne < 0)
            {
                std::cout << "La colonne est pleine!\n";
                colonne = this->askPlayerColumn();//Colonne = colonne entré par le joueur après vérification
                ligne = 5;
            }
        }
        if (colonne == 10)//Si le joueur à quitté
        {
            return;
        }
        grille[ligne][colonne] = jeton; //Placement du jeton
        isWon = this->isWon(joueur);
        if (joueur != rouge)joueur = rouge;
        else if (joueur != jaune)joueur = jaune;
        this->print();

    }
    while(!isWon);

}
