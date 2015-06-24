#ifndef PUISSANCE4_H_INCLUDED
#define PUISSANCE4_H_INCLUDED
#include <array>

enum Couleur {vide ,jaune ,rouge};
using Grille = std::array<std::array<Couleur,7>,6>;
class PuissanceQuatre{
    private:
    Grille grille;
    Couleur jeton;
    public:
    PuissanceQuatre();
    void print();
    bool play();
};

#endif // PUISSANCE4_H_INCLUDED
