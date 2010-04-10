///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 10.04.2010
// Opis: Deklaracja klasy obs³ugi kamery.
///////////////////////////////////////////////////////////////////////////////

#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "map.h"
#include "player.h"

class Camera:
{
public:
	Camera(const Map* _map, const Player* _player);

	void Show();

private:
	const Map* map;
	const Player* player;
};

#endif // _CAMERA_H_ //////////////////////////////////////////////////////////
