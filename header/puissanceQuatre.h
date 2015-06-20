#ifndef PUISSANCE_QUATRE
#define PUISSANCE_QUATRE

#include <iostream>
#include <array>

class Puissance4 {
	private:
	enum Couleur{ vide, rouge, jaune };
	typedef std::array<std::array<Couleur,7>,6> Grille;
	Grille grille;
	bool isGameInit; //Faut il le faire?
	public:
	void initGame();
	void debugPrint();
	void print();
};

#endif
