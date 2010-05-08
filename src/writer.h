///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 16.04.2010
// Data modyfikacji: 8.05.2010
// Opis: Plik zawiera deklarację klasy odpowiedzialnej za wypisywanie tekstu.
///////////////////////////////////////////////////////////////////////////////

#ifndef _WRITER_H_
#define _WRITER_H_

#include <string>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL.h>
#include "global.h"

// Stała wyliczeniowa określająca położenie tekstu.
enum Align
{
	LeftAlign,
	Center
};

class Writer
{
public:
	Writer(std::string& _text, int _x, int _y, SDL_Surface* _surface, Align _align, int size, SDL_Color _color);
	~Writer();

	void Write();
	static void Write(std::string& text, int x, int y, SDL_Surface* surface, Align align = LeftAlign, int size = 15, Color color = Black);

	void SetXY(int _x, int _y) { x = _x; y = _y; }
	int GetX() const { return x; }
	int GetY() const { return y; }

	void SetAlign(Align _align) { align = _align; }
	Align GetAlign() const { return align; }

private:
	std::string text;
	int x, y;
	TTF_Font* font;
	SDL_Surface* surface;
	Align align;
	SDL_Color color;
};

#endif // _WRITER_H_ //////////////////////////////////////////////////////////
