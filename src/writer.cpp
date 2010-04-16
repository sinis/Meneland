///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 16.04.2010
// Data modyfikacji: 16.04.2010
// Opis: Plik zawiera implementacj� klasy odpowiedzialnej za wypisywanie
//  tekstu.
///////////////////////////////////////////////////////////////////////////////

#include "writer.h"
#include <vector>
#include "path.h"

// Konstruktor ////////////////////////////////////////////////////////////////
// Parametry:
//  - _text: std::string& - referencja do tekstu, kt�ry nale�y wypisa�.
//  - _x, _y: int - wsp�rz�dne gdzie wy�wietli� tekst.
//  - _surface: SDL_Surface* - powierzchnia, na kt�rej b�dzie odrysowany tekst.
// Opis:
//  Inicjalizuje obiekt.
Writer::Writer(std::string& _text, int _x, int _y, SDL_Surface* _surface):
	text(_text), x(_x), y(_y), surface(_surface)
{
	font = TTF_OpenFont((Path::GetCWD() + "/data/font.ttf").c_str(), 15);
}

// Desturktor /////////////////////////////////////////////////////////////////
// Opis:
//  Zamyka font.
Writer::~Writer()
{
	TTF_CloseFont(font);
}

// Writer /////////////////////////////////////////////////////////////////////
// Opis:
//  Funkcja odpowiada za zrenderowanie i wy�wietlenie tekstu na ekranie.
//  Najpierw wydziela wszystkie linie, potem renderuje je po kolei i wy�wietla
//  na ekranie.
void Writer::Write()
{
	// Najpierw wylicza wystkie linie w tek�cie. Potem w p�tli ka�d� po kolei
	// przetwarza.

	SDL_Surface* lineSurface;
	SDL_Rect rect;
	std::vector<std::string> linesVector;
	int linesCount = 1;

	// Wylicza linie.
	for (unsigned int i = 0; i < text.length(); i++)
		if (text.c_str()[i] == '\n') linesCount++;

	// Wydziela linie.
	int from = 0;
	for (int i = 0; i < linesCount; i++)
	{
		for (unsigned int j = from + 1; j < text.length(); j++)
		{
			// Je�li znajdzie kolejny '\n', lub znajdzie si�
			// przy ko�cu - wrzuca lini� do vectora.
			if (text[j] == '\n' || j + 1 == text.length())
			{
				linesVector.push_back(text.substr(from, j - from + 1));
				from = j + 1;
				break;
			}
		}
	}

	// P�tla kolejno odrysowuj�ca linie na ekranie.
	for (int i = 0; i < linesCount; i++)
	{
		lineSurface = TTF_RenderText_Blended(font, linesVector.at(i).c_str(), {0, 0, 0});
		rect.x = x;
		rect.y = y;
		SDL_BlitSurface(lineSurface, 0, surface, &rect);
		y += lineSurface->h; // Przesuwa nast�pn� lini� pod aktualn�.
		SDL_FreeSurface(lineSurface);
	}
}

// Writer /////////////////////////////////////////////////////////////////////
// Parametry:
//  - text: std::string& - tekst do wy�wietlenia.
//  - x, y: int - wsk�rz�dne, gdzie wy�wietli� tekst.
//  - surface: SDL_Surface* - powierzchnia, na kt�rej tekst ma zosta�
//    wy�wietlony.
// Opis:
//  Jest to metoda statyczna. Tworzy nowy obiekt Writera o podanych parametrach
//  i przekazuje mu wykonanie w celu odrysowania tekstu. Po wszystkim czy�ci
//  pami��.
void Writer::Write(std::string& text, int x, int y, SDL_Surface* surface)
{
	Writer* writer = new Writer(text, x, y, surface);
	writer->Write();
	delete writer;
}
