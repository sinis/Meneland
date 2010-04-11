///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 11.04.2010
// Opis: Deklaracja klasy obs�uguj�cej map�.
///////////////////////////////////////////////////////////////////////////////

#ifndef _MAP_H_
#define _MAP_H_

#include "field.h"
#include "global.h"

class Map
{
public:
	Map(int& playerX, int& playerY);
	~Map();

	void Show(int fromX, int fromY, int toX, int toY, SDL_Surface* surface);
	bool IsMovePossible(int x, int y, Direction dir);
	void MoveHandling(int x, int y, SDL_Surface* surface);

	int GetWidth() const { return w; }
	int GetHeight() const { return h; }

private:
	int w, h; // Rozmiar mapy.
	Field** map; // Mapa zbudowana z p�l.
};

#endif // _MAP_H_ /////////////////////////////////////////////////////////////
