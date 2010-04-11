///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 11.04.2010
// Opis: Implemntacja obs�ugi przycisku.
///////////////////////////////////////////////////////////////////////////////

#include "button.h"
#include <SDL/SDL_image.h>
#include "global.h"

// Konstruktor ////////////////////////////////////////////////////////////////
// Parametry:
//  - _x, _y: int - po�o�enie buttona.
//  - _text: std::string& - napis na buttonie
// Opis:
//  Inicjalizuje obraz buttona, jego po�o�enie oraz napis na nim.
//  Dodatkowo otwiera czcionk�. TTF_Init() powinno zosta� wywo�ane wcze�niej.
Button::Button(int _x, int _y, const std::string& _text):
	x(_x), y(_y), text(_text)
{
	Visible::SetImage("data/button.png");
	font = TTF_OpenFont("data/font.ttf", 20);
}

// Destruktor /////////////////////////////////////////////////////////////////
// Opis:
//  Zamyka font.
Button::~Button()
{
	TTF_CloseFont(font);
}

// HandleButton ///////////////////////////////////////////////////////////////
// Opis:
//  Funkcja odpowiada za obs�ug� buttona.
//  Ko�czy swoje dzia�anie dopiero w momencie klikni�cia na button. Klikni�cie
//  musi si� odby� na widocznej cz�ci przycisku. (trzeba b�dzie grzeba� za
//  nieprze�roczystymi pikselami)
void Button::HandleButton()
{
	SDL_Event event;
	bool quit = false;

	while (!quit)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEBUTTONDOWN &&
				event.button.button == SDL_BUTTON_LEFT)
			{
				// Klikni�cie lewym przyciskiem myszy.
				// Wypada sprawdzi� czy w obr�bie buttona.
				int mouseX = event.motion.x;
				int mouseY = event.motion.y;

				if (mouseX >= x && mouseX <= image->w + x &&
					mouseY >= y && mouseY <= image->h + y)
				{
					// Czyli jeste�my w prostok�cie mieszcz�cym button.
					// Tutaj wypada sprawdzi� czy klikni�ty piksel nie jest
					// prze�roczysty.

					// Trzeba obliczy� po�o�enie piksela na obrazie przycisku.
					int pixelX = mouseX - x;
					int pixelY = mouseY - y;
					Uint32 pixel = getpixel(image, pixelX, pixelY);
					Uint8 rgba[4];
					SDL_GetRGBA(pixel, image->format, &rgba[0], &rgba[1], &rgba[2], &rgba[3]);

					// Je�li piksel jest nieprze�roczysty zatwierdza klikni�cie.
					if (rgba[3] == 0xff)
						quit = true;
				}
			}
		}
	}
}

// Show ///////////////////////////////////////////////////////////////////////
// Parametr:
//  - surface: SDL_Surface* - powierzchnia, na kt�rej nale�y odrysowa�
//   przycisk.
// Opis:
//  Funkcja odrysowywuje obraz przycisku w podanym po�o�eniu. Potem oblicza
//  gdzie ma odrysowa� napis i robi to.
void Button::Show(SDL_Surface* surface)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	SDL_BlitSurface(image, 0, surface, &rect);

	SDL_Color textColor = { 0, 0, 0};
	SDL_Surface* txt = TTF_RenderText_Blended(font, text.c_str(), textColor);

	// Oblicza przesuni�cie tekstu.
	int xOffset = (image->w - txt->w) / 2 + x;
	int yOffset = (image->h - txt->h) / 2 + y;

	// Odrysowywuje tekst.
	rect.x = xOffset;
	rect.y = yOffset;
	SDL_BlitSurface(txt, 0, surface, &rect);

	// Czy�ci po tek�cie.
	SDL_FreeSurface(txt);
}
