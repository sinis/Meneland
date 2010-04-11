///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 11.04.2010
// Opis: Implementacja komunikat�w.
///////////////////////////////////////////////////////////////////////////////

#include "messagebox.h"
#include <SDL/SDL_image.h>

// Konstruktor ////////////////////////////////////////////////////////////////
// Parametry:
//  - _text: std::string& - referencja na tekst do wy�wietlenia.
//  - _objectImage: SDL_Surface* - wska�nik na powierzchni� z obrazem obiektu.
// Opis:
//  Inicjalizuje obiekt.
MessageBox::MessageBox(std::string& _text, SDL_Surface* _objectImage):
	text(_text), objectImage(_objectImage), button(new Button(400, 300, "OK"))
{
	Visible::SetImage("data/paper.png");
}

// Destruktor /////////////////////////////////////////////////////////////////
// Opis:
//  Usuwa buttona.
MessageBox::~MessageBox()
{
	delete button;
}
