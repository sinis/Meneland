///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 9.04.2010
// Opis: Deklaracja klasy obs³uguj±cej mapê.
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

	void Show(int fromX, int fromY, int toX, int toY);
	bool IsMovePossible(int x, int y, Direction dir);
	void MoveHandling();

private:
	int w, h; // Rozmiar mapy.
	Field map[][]; // Mapa zbudowana z pól.
};

#endif // _MAP_H_ /////////////////////////////////////////////////////////////
