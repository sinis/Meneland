///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 8.05.2010
// Data modyfikacji: 8.05.2010
// Opis: Plik zawiera funkcję pomocną przy oczekiwaniu na upłynięcie czasu
//  lub reakcję usera.
///////////////////////////////////////////////////////////////////////////////

#include <SDL/SDL.h>

// Wait ///////////////////////////////////////////////////////////////////////
// Parametr:
//  - time: Uint32 - czas w milisekundach.
// Opis:
//  Funkcja oczekuje na reakcję użytkownika do upłynięcia czasu podanego
//  w time.
void Wait(Uint32 time)
{
	SDL_Event event;
	Uint32 start = SDL_GetTicks();
	bool quit = false;

	while (!quit)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
				return;
		}

		if (SDL_GetTicks() - start >= time)
			quit = true;
	}
}
