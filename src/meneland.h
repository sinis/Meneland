///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 13.04.2010
// Opis: Deklaracja g³ównej klasy gry.
///////////////////////////////////////////////////////////////////////////////

#ifndef _MENELAND_H_
#define _MENELAND_H_

#include <SDL/SDL.h>

class Meneland
{
public:
	Meneland() {};
	~Meneland();

	bool Init();
	int Execute();

private:
	SDL_Surface* screen;
};
#endif // _MENELAND_H_ ////////////////////////////////////////////////////////
