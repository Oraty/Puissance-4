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
    for (auto& column : grid)   //for every column of "grid"
    {
        for (auto& kase : column) // for every case of every comumn of "grid" //kase = case
        {
            kase = nothing;//set every case to "nothing" (nothing)
        }
    }
}

void PuissanceQuatre::print()  // print 'O' for yellow and 'X' for red
{
    for (unsigned i {0}; i<500; i++)
        std::cout << std::endl;

    for (auto line : grid)      //for every column of "grid"
    {
        std::cout << " |";
        for (auto kase : line)   // for every case of every column of "grid" //kase = case
        {
            if (kase == nothing)
            {
                std::cout << ' ';
            }
            else if(kase == yellow)
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
    std::cout << '=' << '=' << '\n';
}
Color PuissanceQuatre::askPlayerColor()
{
    Color token;
    std::cout << "Quelle est la couleur du premier joueur? (yellow ou red)" << std::endl;
    std::string player;
    std::cin >> player;
    if (std::cin.eof())
    {
        return nothing;
    }
    while (player != "yellow" && player != "red")
    {
        std::cout << "Veuillez rentrer une information comprise entre \" yellow \" et \" red \" \n";
        std::cin >> player;
        if (std::cin.eof())
        {
            return nothing;
        }
    }
    if (player == "yellow")token = yellow;
    else token = red;
    return token;
}

unsigned int PuissanceQuatre::askPlayerColumn()
{
    unsigned int column {0};
    std::cout << "Sur quelle colonne jouer? (1-7)" << std::endl;
    auto isNotQuited = getUInt(column);
    if (column <= 0 || column > 7)
    {
        std::cout << "Veuillez entrer un chiffre entier compris entre 1 et 7 inclus\n";
        isNotQuited = getUInt(column);
    }
    if (!isNotQuited)
    {
        return 10;
    }
    --column; // Make it match with grid index (0-6)
    return column;
}

unsigned int PuissanceQuatre::countTokens(int dir_column,int dir_line,std::size_t column,std::size_t line)
{
    int i {0};
    Color token = grid[line][column];
    if (token == nothing)
    {
        return 1;
    }
    while(line < grid.size() &&
            column < grid[line].size() &&
            grid[line][column] == token)
    {
        line += dir_line;
        column += dir_column;
        i++;
    }
    return i;
}

bool PuissanceQuatre::isWon(Color player)
{
    for(std::size_t line {5}; line < grid.size(); line--)
    {
        for(std::size_t column {0}; column < grid[line].size(); column++)
        {
            if (grid[line][column] == player)
            {
                if (    PuissanceQuatre::countTokens(-1,0,column,line) >= 4 ||
                        PuissanceQuatre::countTokens(-1,+1,column,line) >= 4 ||
                        PuissanceQuatre::countTokens(0,1,column,line) >= 4 ||
                        PuissanceQuatre::countTokens(+1,+1,column,line) >= 4)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
bool PuissanceQuatre::isGridFull()
{
    unsigned int i {0};
    while(grid[0][i] != nothing)
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
    auto player = this->askPlayerColor(); //token = choosed color
    decltype(player)& token {player}; //Creating a reference to player for semantic
    if (token == nothing)//If the player quit with ctrl+D
    {
        return;
    }
    bool isWon {};
    do //Progress of the game
    {
        if(isGridFull())
        {
            std::cout << "\n La grille est pleine!" << std::endl;
            return;
        }
        int line {5};
        auto column = this->askPlayerColumn();
        while (grid[line][column] != nothing)// we browse the column from top to bottom until we found an empty case
        {
            line--;
            if (line < 0)
            {
                std::cout << "La colonne est pleine!\n";
                column = this->askPlayerColumn();//column = column typed by the player after verification
                line = 5;
            }
        }
        if (column == 10)//If the player quit with ctrl+D
        {
            return;
        }
        grid[line][column] = token; //Placement of the token
        isWon = this->isWon(player);
        if (player != red)player = red;
        else if (player != yellow)player = yellow;
        this->print();

    }
    while(!isWon);
    std::cout << "\n\n\
                  ===================\n\
                  ==Vous avez gagné==\n\
                  ===================";
}
