///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 16.04.2010
// Opis: Implementacja obs³ugi playera.
///////////////////////////////////////////////////////////////////////////////

#include "player.h"
#include <SDL/SDL_image.h>
#include "path.h"

// Konstruktor ////////////////////////////////////////////////////////////////
// Parametry:
//  - _x, _y: int - po³o¿enie gracza na mapie.
//  - map: const Map* - sta³y wska¼nik na mapê. (aby gracz móg³ sprawdziæ czy
//   ruch, który chce wykonaæ jest mo¿liwy)
// Opis:
//  Konstruktor inicjalizuje obiekt gracza.
//  Ustawia jego zmienne oraz ³aduje tekstury.
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
//  Czy¶ci po obiekcie - usuwa tekstury.
Player::~Player()
{
	for (int i = 0; i < 4; i++)
		SDL_FreeSurface(textures[i]);
}

// Move ///////////////////////////////////////////////////////////////////////
// Parametr:
//  - _dir: Direction - kierunek, w którym ma siê poruszyæ postaæ gracza.
// Opis:
//  Funkcja sprawdza dziêki wska¼nikowi na mapê, czy ruch mo¿e siê odbyæ.
//  Je¶li tak - przesuwa gracza.
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
//  - _dir: Direction - wskazuje na teksturê.
// Opis:
//  Zmienia teksturê gracza na podstawie argumentu.
void Player::ChangeTexture(Direction _dir)
{
	dir = _dir;
	image = textures[dir];
}
