#include <iostream>
#include "../header/puissanceQuatre.h"

void Puissance4::initGame(){
	Grille grille;
	for (auto line : grille){
		for (auto kase : line){ //kase = case
			kase=vide;
		}
	}
}
