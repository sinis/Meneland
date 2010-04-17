///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 14.04.2010
// Opis: Implementacja głównej klasy gry.
///////////////////////////////////////////////////////////////////////////////

#include "meneland.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "map.h"
#include "player.h"
#include "camera.h"

// Destruktor /////////////////////////////////////////////////////////////////
// Opis:
//  Wyłącza TTF i SDLa.
Meneland::~Meneland()
{
	TTF_Quit();
	SDL_Quit();
}

// Init ///////////////////////////////////////////////////////////////////////
// Opis:
//  Inicjalizuje SDLa, TTFa i tworzy screena.
// Zwraca:
//  - true - jeśli się powiodło.
//  - false - jeśli nie.
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
//  Główna funkcja programu/gry/czegoś.
// Zwraca:
//  - 0 - jeśli wszystko ok.
//  - -1 - jeśli błąd.
int Meneland::Execute()
{
	// Na początku tworzy Mapę, Playera i Camerę. Ustawia playerowi miejsce
	// na planszy i przechodzi do głównej pętli.
	int playerX, playerY;
	Uint8* keystate = SDL_GetKeyState(0);
	bool quit = false;
	Map* map = new Map(playerX, playerY);
	Player* player = new Player(playerX, playerY, map);
	Camera* camera = new Camera(map, player, screen);

	camera->Show();
	// Główna pętla.
	// Obsługuje klawisza pociśnięcie. Jeśli trzeba ruch wykonuje. Kończy się
	// gdy gracz wejdzie na pole wyjścia.
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
