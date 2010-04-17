///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 10.04.2010
// Opis: Deklaracja klasy bazowej dla widocznych obiektów w grze.
///////////////////////////////////////////////////////////////////////////////

#ifndef _VISIBLE_H_
#define _VISIBLE_H_

#include <SDL/SDL.h>

class Visible
{
public:
	Visible(const char* fileName = 0);
	~Visible();

	bool SetImage(const char* fileName);
	virtual void Show(int x, int y, SDL_Surface* surface);

protected:
	SDL_Surface* image; // Obraz do wyświetlenia.
};

#endif // _VISIBLE_H_ /////////////////////////////////////////////////////////
