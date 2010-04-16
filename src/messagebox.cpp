///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 16.04.2010
// Opis: Implementacja komunikat�w.
///////////////////////////////////////////////////////////////////////////////

#include "messagebox.h"
#include <SDL/SDL_image.h>
//#include <SDL/SDL_ttf.h>
#include "writer.h"
#include "path.h"

// Konstruktor ////////////////////////////////////////////////////////////////
// Parametry:
//  - _text: std::string& - referencja na tekst do wy�wietlenia.
//  - _objectImage: SDL_Surface* - wska�nik na powierzchni� z obrazem obiektu.
// Opis:
//  Inicjalizuje obiekt, oraz czcionki.
MessageBox::MessageBox(std::string& _text, SDL_Surface* _objectImage):
	button(new Button(400, 300, "OK")), text(_text), objectImage(_objectImage)
{
	Visible::SetImage((Path::GetCWD() + "/data/paper.png").c_str());
	//font = TTF_OpenFont("data/font.ttf", 15);
}

// Destruktor /////////////////////////////////////////////////////////////////
// Opis:
//  Usuwa buttona i zamyka czcionk�.
MessageBox::~MessageBox()
{
	delete button;
	//TTF_CloseFont(font);
}

// Show ///////////////////////////////////////////////////////////////////////
// Parametr:
//  - surface: SDL_Surface* - powierzchnia, na kt�rej wy�wietlony ma by�
//   komunikat.
// Opis:
//  Funkcja wy�wietla komunikat oraz przekazuje obs�ug� do buttona.
void MessageBox::Show(SDL_Surface* surface)
{
	// Wy�wietla komunikat w zale�no�ci od tego czy zosta� okre�lony obraz
	// obiektu. Je�li tak: wy�wietla go po lewej, a tekst po jego prawej.
	// Je�li nie - wy�wietla tekst na �rodku.

	SDL_Rect rect; // Zmienna pomocnicza - do odrysowywania.
	//SDL_Color fg = {0, 0, 0};
	//SDL_Surface* txt = TTF_RenderText_Blended(font, text.c_str(), fg);

	// Najpierw odrysowywuje papier.
	int paperX = rect.x = (surface->w - image->w)/2;
	int paperY = rect.y = (surface->h - image->h)/2;
	SDL_BlitSurface(image, 0, surface, &rect);

	if (objectImage)
	{
		// Odrysowywuje obraz obiektu.
		rect.x = 0; //(surface->w - objectImage->w)/2;
		rect.y = (surface->h - objectImage->h)/2;
		SDL_BlitSurface(objectImage, 0, surface, &rect);

		// Odrysowywuje tekst obok.
		rect.x = objectImage->w + 5; //(surface->w - txt->w) /2 + objectImage->w + 10;
		rect.y = paperY + 10; //(surface->h - txt->h) /2;
		//SDL_BlitSurface(txt, 0, surface, &rect);
		Writer::Write(text, rect.x, rect.y, surface);
	}
	else
	{
		// Odrysowywuje tekst na �rodku.
		rect.x = paperX + 10; //(surface->w - txt->w) / 2;
		rect.y = paperY + 10; //(surface->h - txt->h) / 2;
		//SDL_BlitSurface(txt, 0, surface, &rect);
		Writer::Write(text, rect.x, rect.y, surface);
	}

	// Odrysowywuje button i przekazuje wykonanie.
	button->Show(surface);
	button->HandleButton();

	//SDL_FreeSurface(txt);
}

// Show ///////////////////////////////////////////////////////////////////////
// Parametry:
//  - _text: std::string& - tekst do wy�wietlenia.
//  - _objectImage: SDL_Surface* - wska�nik na obraz obiektu.
//  - surface: SDL_Surface* - wska�nik na powierzchni�.
// Opis:
//  Jako statyczna funkcja tworzy nowy obiekt MessageBoxa wedle podanych
//  parametr�w. Wy�wietla go i przekazuje obs�ug� i na ko�cu czy�ci po nim.
void MessageBox::Show(std::string& _text, SDL_Surface* _objectImage, SDL_Surface* surface)
{
	MessageBox* mb = new MessageBox(_text, _objectImage);
	mb->Show(surface);
	delete mb;
}
