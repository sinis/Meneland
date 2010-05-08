///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 8.05.2010
// Data modyfikacji: 8.05.2010
// Opis: Plik zawiera implementację wprowadzenia do 'gry'.
///////////////////////////////////////////////////////////////////////////////

#include "intro.h"
#include <string>
#include "writer.h"
#include "global.h"
#include "messagebox.h"

// Show ///////////////////////////////////////////////////////////////////////
// Parametr:
//  - screen: SDL_Surface* - wskaźnik na powierzchnię ekranu.
// Opis:
//  Jest to jedyna funkcja klasy intro. Odpowiada za obsługę wprowadzenia.
void Intro::Show(SDL_Surface* screen)
{
	// Dobra, wiem, że ten kod mógł wyglądać lepiej... xD

	std::string text;
	// Czyści ekran na czarno i wyświetla napis z wprowadzeniem.
	SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0, 0, 0));
	text = "Na podstawie idei\n\"zróbmy coś głupiego\"...";
	Writer::Write(text, 0, 150, screen, Center, 30, White);
	SDL_Flip(screen);
	Wait(3000);

	SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0, 0, 0));
	text = "Sinis przedstawia...";
	Writer::Write(text, 0, 200, screen, Center, 30, White);
	SDL_Flip(screen);
	Wait(2000);

	SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0, 0, 0));
	text = "Menelandia";
	Writer::Write(text, 0, 180, screen, Center, 60, White);
	SDL_Flip(screen);
	Wait(3000);

	text = "No więc wkopał(eś/aś) się. Uruchomienie tego wytworu\n"
		   "imitującego grę jest Twoim błędem. Brak tu funkcji wyjścia\n"
		   "więc, jeśli chcesz wyjść, musisz znaleźć wyjście.\n"
		   " Oczywiście zawsze można skorzystać z opcji zwanej\n"
		   "\"Menadżerem zadań\", ale po co?\n"
		   "Może coś znajdziesz po drodze.\n"
		   "Do boju!\n  \n"
		   "Aha... Jakby się miało za chwilę przywiesić to poczekaj.\n"
		   "Mapa się musi załadować.";
	MessageBox::Show(text, 0, screen);
}
