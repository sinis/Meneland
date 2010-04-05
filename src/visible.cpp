///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 5.04.2010
// Opis: Implementacja klasy bazowej dla widocznych obiekt�w.
///////////////////////////////////////////////////////////////////////////////

#include "visible.h"
#include <SDL/SDL_image.h>

// Konstruktor ////////////////////////////////////////////////////////////////
// Opis:
//  Inicjalizuje obiekt. Je�li podano nazw� pliku - pr�buje za�adowa� obraz.
Visible::Visible(const char* fileName):
	image(0)
{
	if (fileName)
	{
		image = IMG_Load(fileName);
	}
}

// Destruktor /////////////////////////////////////////////////////////////////
// Opis:
//  Czy�ci po obiekcie. Je�li utworzono wcze�niej w pami�ci obraz - usuwa go.
Visible::~Visible()
{
	if (image)
		SDL_FreeSurface(image);
}

// setImage ///////////////////////////////////////////////////////////////////
// Parametr:
//  - fileName: const char* - nazwa pliku z obrazem.
// Opis:
//  Funkcja ustawia obraz obiektu. Je�li obraz wcze�niej istnia� - usuwa go.
// Zwraca:
//  - true - je�li uda�o si� za�adowa� obraz
//  - false - w razie niepowodzenia.
bool Visible::SetImage(const char* fileName)
{
	if (!fileName) return false;

	if (image)
	{
		SDL_FreeSurface(image);
		image = 0;
	}

	image = IMG_Load(fileName);

	if (!image) return false;
	return true;
}

// Show ///////////////////////////////////////////////////////////////////////
// Parametry:
//  - x, y: integer - wsp�rz�dne
//  - surface: SDL_Surface - powierzchnia
// Opis:
//  Funkcja wy�wietla obraz na podanej powierzchni.
void Visible::Show(int x, int y, SDL_Surface* surface)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	SDL_BlitSurface(image, 0, surface, &rect);
}
