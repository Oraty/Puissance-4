#ifndef PUISSANCE4_H_INCLUDED
#define PUISSANCE4_H_INCLUDED
#include <array>

enum Couleur {vide, jaune, rouge};
using Grille = std::array<std::array<Couleur,7>,6>;
class PuissanceQuatre
{
private:
    Grille grille;
    Couleur askPlayerColor();
    unsigned int askPlayerColumn();
    unsigned int countTokens(int,int,std::size_t,std::size_t);
    bool isWon(Couleur);
    bool isGrillePleine();
public:
    PuissanceQuatre();
    PuissanceQuatre(PuissanceQuatre const&) = delete;
    PuissanceQuatre operator=(PuissanceQuatre const&) = delete;
    void print();
    void play();
};

#endif // PUISSANCE4_H_INCLUDED
