///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 13.04.2010
// Opis: Implementacja g³ównej klasy gry.
///////////////////////////////////////////////////////////////////////////////

#include "meneland.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "map.h"
#include "player.h"
#include "camera.h"

// Destruktor /////////////////////////////////////////////////////////////////
// Opis:
//  Wy³±cza TTF i SDLa.
Meneland::~Meneland()
{
	TTF_Quit();
	SDL_Quit();
}

// Init ///////////////////////////////////////////////////////////////////////
// Opis:
//  Inicjalizuje SDLa, TTFa i tworzy screena.
// Zwraca:
//  - true - je¶li siê powiod³o.
//  - false - je¶li nie.
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
//  G³ówna funkcja programu/gry/czego¶.
// Zwraca:
//  - 0 - je¶li wszystko ok.
//  - -1 - je¶li b³±d.
int Meneland::Execute()
{
	// Na pocz±tku tworzy Mapê, Playera i Camerê. Ustawia playerowi miejsce
	// na planszy i przechodzi do g³ównej pêtli.
	int playerX, playerY;
	Uint8* keystate = SDL_GetKeyState(0);
	bool quit = false;
	Map* map = new Map(playerX, playerY);
	Player* player = new Player(playerX, playerY, map);
	Camera* camera = new Camera(map, player, screen);

	camera->Show();
	// G³ówna pêtla.
	// Obs³uguje klawisza poci¶niêcie. Je¶li trzeba ruch wykonuje. Koñczy siê
	// gdy gracz wejdzie na pole wyj¶cia.
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

		SDL_Delay(100);
	}

	return 0;
}
