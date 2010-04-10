///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 10.04.2010
// Opis: Deklaracja klasy obs�uguj�cej map�.
///////////////////////////////////////////////////////////////////////////////

#ifndef _MAP_H_
#define _MAP_H_

#include "field.h"
#include "global.h"
#include "player.h"

class Map
{
public:
	Map(Player* player);
	~Map();

	void Show(int fromX, int fromY, int toX, int toY, SDL_Surface* surface);
	bool IsMovePossible(int x, int y, Direction dir);
	void MoveHandling(int x, int y);

private:
	int w, h; // Rozmiar mapy.
	Field** map; // Mapa zbudowana z p�l.
};

#endif // _MAP_H_ /////////////////////////////////////////////////////////////
