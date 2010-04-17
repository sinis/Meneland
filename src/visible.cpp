///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 5.04.2010
// Opis: Implementacja klasy bazowej dla widocznych obiektów.
///////////////////////////////////////////////////////////////////////////////

#include "visible.h"
#include <SDL/SDL_image.h>

// Konstruktor ////////////////////////////////////////////////////////////////
// Opis:
//  Inicjalizuje obiekt. Jeśli podano nazwę pliku - próbuje załadować obraz.
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
//  Czyści po obiekcie. Jeśli utworzono wcześniej w pamięci obraz - usuwa go.
Visible::~Visible()
{
	if (image)
		SDL_FreeSurface(image);
}

// setImage ///////////////////////////////////////////////////////////////////
// Parametr:
//  - fileName: const char* - nazwa pliku z obrazem.
// Opis:
//  Funkcja ustawia obraz obiektu. Jeśli obraz wcześniej istniał - usuwa go.
// Zwraca:
//  - true - jeśli udało się załadować obraz
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
//  - x, y: integer - współrzędne
//  - surface: SDL_Surface - powierzchnia
// Opis:
//  Funkcja wyświetla obraz na podanej powierzchni.
void Visible::Show(int x, int y, SDL_Surface* surface)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	SDL_BlitSurface(image, 0, surface, &rect);
}
