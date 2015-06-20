#include <iostream>
#include "../header/puissanceQuatre.h"

void Puissance4::initGame(){
	for (auto line : grille){
		for (auto kase : line){ //kase = case
			kase=vide;
		}
	}
isGameInit = true; //Faut il le faire?
}

void Puissance4::debugPrint(){
	
}
