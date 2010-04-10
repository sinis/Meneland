///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 9.04.2010
// Opis: Implementacja obs�ugi playera.
///////////////////////////////////////////////////////////////////////////////

#include "player.h"
#include <SDL/SDL_image.h>

// Konstruktor ////////////////////////////////////////////////////////////////
// Parametry:
//  - _x, _y: int - po�o�enie gracza na mapie.
//  - map: const Map* - sta�y wska�nik na map�. (aby gracz m�g� sprawdzi� czy
//   ruch, kt�ry chce wykona� jest mo�liwy)
// Opis:
//  Konstruktor inicjalizuje obiekt gracza.
//  Ustawia jego zmienne oraz �aduje tekstury.
Player::Player(int _x, int _y, Map* _map):
	x(_x), y(_y), map(_map), dir(Down)
{
	textures[Down] = IMG_Load("data/players.png");
	textures[Up] = IMG_Load("data/playern.png");
	textures[Left] = IMG_Load("data/playere.png");
	textures[Right] = IMG_Load("data/playerw.png");

	image = textures[Down];
}

// Destruktor /////////////////////////////////////////////////////////////////
// Opis:
//  Czy�ci po obiekcie - usuwa tekstury.
Player::~Player()
{
	for (int i = 0; i < 4; i++)
		SDL_FreeSurface(textures[i]);
}

// Move ///////////////////////////////////////////////////////////////////////
// Parametr:
//  - _dir: Direction - kierunek, w kt�rym ma si� poruszy� posta� gracza.
// Opis:
//  Funkcja sprawdza dzi�ki wska�nikowi na map�, czy ruch mo�e si� odby�.
//  Je�li tak - przesuwa gracza.
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
//  - _dir: Direction - wskazuje na tekstur�.
// Opis:
//  Zmienia tekstur� gracza na podstawie argumentu.
void Player::ChangeTexture(Direction _dir)
{
	dir = _dir;
	image = textures[dir];
}
