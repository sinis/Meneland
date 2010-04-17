///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 16.04.2010
// Opis: Implemntacja obsługi przycisku.
///////////////////////////////////////////////////////////////////////////////

#include "button.h"
#include <SDL/SDL_image.h>
#include "global.h"
#include "path.h"

// Konstruktor ////////////////////////////////////////////////////////////////
// Parametry:
//  - _x, _y: int - położenie buttona.
//  - _text: std::string& - napis na buttonie
// Opis:
//  Inicjalizuje obraz buttona, jego położenie oraz napis na nim.
//  Dodatkowo otwiera czcionkę. TTF_Init() powinno zostać wywołane wcześniej.
Button::Button(int _x, int _y, const std::string& _text):
	x(_x), y(_y), text(_text)
{
	Visible::SetImage((Path::GetCWD() + "/data/button.png").c_str());
	font = TTF_OpenFont((Path::GetCWD() + "/data/font.ttf").c_str(), 20);
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
//  Funkcja odpowiada za obsługę buttona.
//  Kończy swoje działanie dopiero w momencie kliknięcia na button. Kliknięcie
//  musi się odbyć na widocznej części przycisku. (trzeba będzie grzebać za
//  nieprzeźroczystymi pikselami)
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
				// Kliknięcie lewym przyciskiem myszy.
				// Wypada sprawdzić czy w obrębie buttona.
				int mouseX = event.motion.x;
				int mouseY = event.motion.y;

				if (mouseX >= x && mouseX <= image->w + x &&
					mouseY >= y && mouseY <= image->h + y)
				{
					// Czyli jesteśmy w prostokącie mieszczącym button.
					// Tutaj wypada sprawdzić czy kliknięty piksel nie jest
					// przeźroczysty.

					// Trzeba obliczyć położenie piksela na obrazie przycisku.
					int pixelX = mouseX - x;
					int pixelY = mouseY - y;
					Uint32 pixel = getpixel(image, pixelX, pixelY);
					Uint8 rgba[4];
					SDL_GetRGBA(pixel, image->format, &rgba[0], &rgba[1], &rgba[2], &rgba[3]);

					// Jeśli piksel jest nieprzeźroczysty zatwierdza kliknięcie.
					if (rgba[3] == 0xff)
						quit = true;
				}
			}
		}
		SDL_Delay(100); // Żeby procesora nie jeść.
	}
}

// Show ///////////////////////////////////////////////////////////////////////
// Parametr:
//  - surface: SDL_Surface* - powierzchnia, na której należy odrysować
//   przycisk.
// Opis:
//  Funkcja odrysowywuje obraz przycisku w podanym położeniu. Potem oblicza
//  gdzie ma odrysować napis i robi to.
void Button::Show(SDL_Surface* surface)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	SDL_BlitSurface(image, 0, surface, &rect);

	SDL_Color textColor = { 0, 0, 0};
	SDL_Surface* txt = TTF_RenderText_Blended(font, text.c_str(), textColor);

	// Oblicza przesunięcie tekstu.
	int xOffset = (image->w - txt->w) / 2 + x;
	int yOffset = (image->h - txt->h) / 2 + y;

	// Odrysowywuje tekst.
	rect.x = xOffset;
	rect.y = yOffset;
	SDL_BlitSurface(txt, 0, surface, &rect);

	SDL_Flip(surface);

	// Czyści po tekście.
	SDL_FreeSurface(txt);
}
