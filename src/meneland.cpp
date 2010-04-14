///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 14.04.2010
// Opis: Implementacja g��wnej klasy gry.
///////////////////////////////////////////////////////////////////////////////

#include "meneland.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "map.h"
#include "player.h"
#include "camera.h"

// Destruktor /////////////////////////////////////////////////////////////////
// Opis:
//  Wy��cza TTF i SDLa.
Meneland::~Meneland()
{
	TTF_Quit();
	SDL_Quit();
}

// Init ///////////////////////////////////////////////////////////////////////
// Opis:
//  Inicjalizuje SDLa, TTFa i tworzy screena.
// Zwraca:
//  - true - je�li si� powiod�o.
//  - false - je�li nie.
bool Meneland::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return false;
	if (TTF_Init() < 0)
		return false;

	screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
	if (!screen)
		return false;

	SDL_WM_SetCaption("Meneland made by Sinis", 0);

	return true;
}

// Execute ////////////////////////////////////////////////////////////////////
// Opis:
//  G��wna funkcja programu/gry/czego�.
// Zwraca:
//  - 0 - je�li wszystko ok.
//  - -1 - je�li b��d.
int Meneland::Execute()
{
	// Na pocz�tku tworzy Map�, Playera i Camer�. Ustawia playerowi miejsce
	// na planszy i przechodzi do g��wnej p�tli.
	int playerX, playerY;
	Uint8* keystate = SDL_GetKeyState(0);
	bool quit = false;
	Map* map = new Map(playerX, playerY);
	Player* player = new Player(playerX, playerY, map);
	Camera* camera = new Camera(map, player, screen);

	camera->Show();
	// G��wna p�tla.
	// Obs�uguje klawisza poci�ni�cie. Je�li trzeba ruch wykonuje. Ko�czy si�
	// gdy gracz wejdzie na pole wyj�cia.
	while (!quit)
	{
		// Ruch
		if (keystate[SDLK_UP])
			player->Move(Up);
		else if (keystate[SDLK_DOWN])
			player->Move(Down);
		else if (keystate[SDLK_LEFT])
			player->Move(Left);
		else if (keystate[SDLK_RIGHT])
			player->Move(Right);

		camera->Show();

		if (map->MoveHandling(player->GetX(), player->GetY(), screen) == Exit)
			quit = true;

		SDL_PumpEvents();
		SDL_Delay(90);
	}

	return 0;
}
