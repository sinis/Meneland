///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 9.05.2010
// Opis: Implementacja głównej klasy gry.
///////////////////////////////////////////////////////////////////////////////

#include "meneland.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "map.h"
#include "player.h"
#include "camera.h"
#include "intro.h"
#include "writer.h"

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
	// No dobra, ale najpierw intro.
	Intro::Show(screen);

	// Na początku tworzy Mapę, Playera i Camerę. Ustawia playerowi miejsce
	// na planszy i przechodzi do głównej pętli.
	int playerX, playerY;
	SDL_Event event;
	Direction dir; // Kierunek ruchu.
	bool moving = false; // Czy gracz jest w ruchu?
	//Uint8* keystate = SDL_GetKeyState(0);
	bool quit = false;
	Map* map = new Map(playerX, playerY);
	Player* player = new Player(playerX, playerY, map);
	Camera* camera = new Camera(map, player, screen);
	const int fps = 10;
	int startTicks = 0;

	camera->Show();
	// Główna pętla.
	// Obsługuje klawisza pociśnięcie. Jeśli trzeba ruch wykonuje. Kończy się
	// gdy gracz wejdzie na pole wyjścia.
	while (!quit)
	{
		startTicks = SDL_GetTicks();
		// Ruch
		/*if (keystate[SDLK_UP])
			player->Move(Up);
		else if (keystate[SDLK_DOWN])
			player->Move(Down);
		else if (keystate[SDLK_LEFT])
			player->Move(Left);
		else if (keystate[SDLK_RIGHT])
			player->Move(Right);*/
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
					case SDLK_DOWN: moving = true; dir = Down; break;
					case SDLK_UP: moving = true; dir = Up; break;
					case SDLK_RIGHT: moving = true; dir = Right; break;
					case SDLK_LEFT: moving = true; dir = Left; break;
				}
			}
			else if (event.type == SDL_KEYUP)
			{
				int sym = event.key.keysym.sym;
				if (sym == SDLK_DOWN || sym == SDLK_UP || sym == SDLK_LEFT || sym == SDLK_RIGHT)
					moving = false;
			}
		}

		if (moving) player->Move(dir);

		camera->Show();

		switch (map->MoveHandling(player->GetX(), player->GetY(), screen))
		{
			case Exit: quit = true; break;
			case HadObject: moving = false; break; // Żeby gracz nie leciał do przodu.
		}

		if (SDL_GetTicks() - startTicks < 1000 / fps)
			SDL_Delay(1000/fps - (SDL_GetTicks() - startTicks));
	}

	// Outro.
	// Matko, co ja robię...
	std::string text = "No i game over.";
	SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0, 0, 0));
	Writer::Write(text, 0, 200, screen, Center, 30, White);
	SDL_Flip(screen);
	Wait(2000);

	text = "Wiem, że nie było fajnie.";
	SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0, 0, 0));
	Writer::Write(text, 0, 200, screen, Center, 30, White);
	SDL_Flip(screen);
	Wait(2000);

	text = "Ale nie martw się. Kontynuacji nie będzie.";
	SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0, 0, 0));
	Writer::Write(text, 0, 200, screen, Center, 30, White);
	SDL_Flip(screen);
	Wait(3000);

	text = "Pozdrawiam.\nSinis";
	SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0, 0, 0));
	Writer::Write(text, 0, 200, screen, Center, 30, White);
	SDL_Flip(screen);
	Wait(2000);

	text = "A tak poza tym to podziękowania dla Promhylerów.";
	SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0, 0, 0));
	Writer::Write(text, 0, 200, screen, Center, 30, White);
	SDL_Flip(screen);
	Wait(3000);

	text = "Dobranoc.";
	SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0, 0, 0));
	Writer::Write(text, 0, 200, screen, Center, 30, White);
	SDL_Flip(screen);
	Wait(2000);

	return 0;
}
