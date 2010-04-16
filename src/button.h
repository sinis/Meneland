///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 16.04.2010
// Opis: Deklaracja klasy obs³uguj±cej przyciski.
///////////////////////////////////////////////////////////////////////////////

#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string>
#include "visible.h"

class Button: public Visible
{
public:
	Button(int _x, int _y, const std::string& _text);
	virtual ~Button();

	void HandleButton();
	void Show(SDL_Surface* surface);

private:
	int x, y; // Po³o¿enie buttona.
	std::string text; // Tekst na buttonie.
	TTF_Font* font; // Font buttona.
};

#endif // _BUTTON_H_ //////////////////////////////////////////////////////////
