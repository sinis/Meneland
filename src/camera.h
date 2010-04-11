///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 10.04.2010
// Opis: Deklaracja klasy obs³ugi kamery.
///////////////////////////////////////////////////////////////////////////////

#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <SDL/SDL.h>
#include "player.h"
#include "map.h"

class Camera
{
public:
	Camera(Map* _map, Player::Player* _player, SDL_Surface* _surface);

	void Show();

private:
	Map* map;
	Player::Player* player;
	SDL_Surface* surface;
};

#endif // _CAMERA_H_ //////////////////////////////////////////////////////////
