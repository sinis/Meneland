///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 9.04.2010
// Opis: Deklaracja klasy odpowiedzialnej za obs�ug� playera.
///////////////////////////////////////////////////////////////////////////////

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <SDL/SDL.h>
#include "visible.h"
#include "map.h"
#include "global.h"

class Player: public Visible
{
public:
	Player(int _x, int _y, const Map* _map);
	~Player();

	int GetX() const { return x; }
	void SetX(int _x) { x = _x; }
	int GetY() const { return y; }
	void SetY(int _y) { y = _y; }

	void Move(Direction _dir);

private:
	void ChangeTexture(Direction _dir);

private:
	int x, y; // Wsp�rz�dne gracza.
	Direction dir; // Ustawienie gracza.
	SDL_Surface* textures[4]; // Jego tekstury.
	const Map* map;
};

#endif // _PLAYER_H_ //////////////////////////////////////////////////////////
