#ifndef PUISSANCE4_H_INCLUDED
#define PUISSANCE4_H_INCLUDED
#include <array>

enum Color {nothing, yellow, red};
using Grid = std::array<std::array<Color,7>,6>;
class PuissanceQuatre
{
private:
    Grid grid;
    Color askPlayerColor();
    unsigned int askPlayerColumn();
    unsigned int countTokens(int,int,std::size_t,std::size_t);
    bool isWon(Color);
    bool isGridFull();
public:
    PuissanceQuatre();
    PuissanceQuatre(PuissanceQuatre const&) = delete;
    PuissanceQuatre operator=(PuissanceQuatre const&) = delete;
    void print();
    void play();
};

#endif // PUISSANCE4_H_INCLUDED
