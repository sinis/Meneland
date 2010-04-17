///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 16.04.2010
// Opis: Implementacja obsługi playera.
///////////////////////////////////////////////////////////////////////////////

#include "player.h"
#include <SDL/SDL_image.h>
#include "path.h"

// Konstruktor ////////////////////////////////////////////////////////////////
// Parametry:
//  - _x, _y: int - położenie gracza na mapie.
//  - map: const Map* - stały wskaźnik na mapę. (aby gracz mógł sprawdzić czy
//   ruch, który chce wykonać jest możliwy)
// Opis:
//  Konstruktor inicjalizuje obiekt gracza.
//  Ustawia jego zmienne oraz ładuje tekstury.
Player::Player(int _x, int _y, Map* _map):
	x(_x), y(_y), dir(Down), map(_map)
{
	textures[Down] = IMG_Load((Path::GetCWD() + "/data/players.png").c_str());
	textures[Up] = IMG_Load((Path::GetCWD() + "/data/playern.png").c_str());
	textures[Left] = IMG_Load((Path::GetCWD() + "/data/playere.png").c_str());
	textures[Right] = IMG_Load((Path::GetCWD() + "/data/playerw.png").c_str());

	image = textures[Down];
}

// Destruktor /////////////////////////////////////////////////////////////////
// Opis:
//  Czyści po obiekcie - usuwa tekstury.
Player::~Player()
{
	for (int i = 0; i < 4; i++)
		SDL_FreeSurface(textures[i]);
}

// Move ///////////////////////////////////////////////////////////////////////
// Parametr:
//  - _dir: Direction - kierunek, w którym ma się poruszyć postać gracza.
// Opis:
//  Funkcja sprawdza dzięki wskaźnikowi na mapę, czy ruch może się odbyć.
//  Jeśli tak - przesuwa gracza.
void Player::Move(Direction _dir)
{
	if (map->IsMovePossible(x, y, _dir))
	{
		switch (_dir)
		{
			case Down:
				y++;
				break;
			case Up:
				y--;
				break;
			case Left:
				x--;
				break;
			case Right:
				x++;
				break;
		}
		ChangeTexture(_dir);
	}
}

// ChangeTexture //////////////////////////////////////////////////////////////
// Parametr:
//  - _dir: Direction - wskazuje na teksturę.
// Opis:
//  Zmienia teksturę gracza na podstawie argumentu.
void Player::ChangeTexture(Direction _dir)
{
	dir = _dir;
	image = textures[dir];
}
