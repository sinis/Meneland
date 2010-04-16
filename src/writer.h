///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 16.04.2010
// Data modyfikacji: 16.04.2010
// Opis: Plik zawiera deklaracjê klasy odpowiedzialnej za wypisywanie tekstu.
///////////////////////////////////////////////////////////////////////////////

#ifndef _WRITER_H_
#define _WRITER_H_

#include <string>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL.h>

class Writer
{
public:
	Writer(std::string& _text, int _x, int _y, SDL_Surface* _surface);
	~Writer();

	void Write();
	static void Write(std::string& text, int x, int y, SDL_Surface* surface);

	void SetXY(int _x, int _y) { x = _x; y = _y; }
	int GetX() const { return x; }
	int GetY() const { return y; }

private:
	std::string text;
	int x, y;
	TTF_Font* font;
	SDL_Surface* surface;
};

#endif // _WRITER_H_ //////////////////////////////////////////////////////////
