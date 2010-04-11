///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 11.04.2010
// Opis: Deklaracja klasy odpowiedzialnej za okna z komunikatami.
///////////////////////////////////////////////////////////////////////////////

#ifndef _MESSAGEBOX_H_
#define _MESSAGEBOX_H_

#include <SDL/SDL.h>
#include <string>
#include "visible.h"
#include "button.h"

class MessageBox: public Visible
{
public:
	MessageBox(std::string& _text, SDL_Surface* _objectImage = 0);
	~MessageBox();

	static void Show(std::string& _text, SDL_Surface* _objectImage, SDL_Surface* surface);
	void Show(SDL_Surface* surface);

	void SetText(std::string& _text) { text = _text; }
	const std::string& GetText() const { return text; }

	void SetObjectImage(SDL_Surface* _objectImage) { objectImage = _objectImage; }

private:
	Button* button;
	std::string text;
	SDL_Surface* objectImage;
};

#endif // _MESSAGEBOX_H_ //////////////////////////////////////////////////////
