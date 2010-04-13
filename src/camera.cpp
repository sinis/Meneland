///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 10.04.2010
// Opis: Implementacja obs³ugi kamery.
///////////////////////////////////////////////////////////////////////////////

#include "camera.h"

// Konstruktor ////////////////////////////////////////////////////////////////
// Parametry:
//  - _map: const Map* - wska¼nik na mapê.
//  - _player: const Player* - wska¼nik na gracza.
//  - _surface: SDL_Surface* - powierzchnia gry.
// Opis:
//  Inicjalizuje wska¼niki wymagane do odrysowywania gry.
Camera::Camera(Map* _map, Player* _player, SDL_Surface* _surface):
	map(_map), player(_player), surface(_surface)
{}

// Show ///////////////////////////////////////////////////////////////////////
// Opis:
//  Pobiera informacje o po³o¿eniu gracza, oblicza, które pola maj± zostaæ
//  wy¶wietlone, wy¶wietla je i umieszcza na nich gracza.
void Camera::Show()
{
	// Standardowo funkcja ma obliczaæ pola do wy¶wietlenia tak, ¿eby gracz
	// by³ na ¶rodku widocznej czê¶ci mapy.
	// Je¶li gracz znajduje siê przy której¶ z krawêdzi mapy, funkcja powinna
	// wy¶wietliæ tyle pól ile mo¿e, a gracza gdzie¶ na nich.
	// Okno gry bêdzie w rozdzielczo¶ci 640x480 -> 16x12 pól.
	// Gracz bêdzie odrysowywany na polu 8x6 (7x5).
	// Wspó³rzêdne gracza powinny zostaæ wymno¿one przez 40, poniewa¿ wy¶wietla
	// on tekstury wedle pikseli.

	int playerX = player->GetX();
	int playerY = player->GetY();
	int fromX;
	int fromY;

	// Je¶li mo¿na, pokazuje playera na ¶rodku mapy.
	/*if (playerX >= 7 && playerY >= 5 &&
		playerX <= map->GetWidth() - 8 && playerY <= map->GetHeight() - 5)
	{
		// Oblicza pola do wy¶wietlenia.
		fromX = playerX - 7;
		fromY = playerY - 5;

		// To samo z graczem.
		playerX = (fromX - playerX) * 40;
		playerY = (fromY - playerY) * 40;

	}*/ // Tego ifa trzeba rozbiæ.

	// Standardowe ustawienia dla pozycji X w zakresie.
	if (playerX >= 7 && playerX <= map->GetWidth() - 8)
	{
		fromX = playerX - 7;
		playerX = (playerX - fromX) * 40;
	}
	// Ustawienia dla X mniejszego od zakresu.
	else if (playerX < 7)
	{
		fromX = 0;
		playerX *= 40;
	}
	// Ustawienia dla X poza zakresem.
	else
	{
		fromX = map->GetWidth() - 8;
		playerX = (playerX - fromX) * 40;
	}

	// Standardowe ustawienia dla pozycji Y w zakresie.
	if (playerY >= 5 && playerY <= map->GetHeight() - 5)
	{
		fromY = playerY - 5;
		playerY = (playerY - fromY) * 40;
	}
	else if (playerY < 5)
	{
		fromY = 0;
		playerY *= 40;
	}
	// Ustawienia dla X poza zakresem.
	else
	{
		fromY = map->GetHeight() - 6;
		playerY = (playerY - fromY) * 40;
	}

	// No ta... Nie wzi±³em pod uwagê sytuacji, gdy rozmiar mapy jest mniejszy ni¿
	// 16x8.
	int toX = fromX + 15, toY = fromY + 7;
	if (toX >= map->GetWidth()) toX = map->GetWidth();
	if (toY >= map->GetHeight()) toY = map->GetHeight();

	// Wy¶wietlenie wszystkiego wedle ustawieñ.
	map->Show(fromX, fromY, toX, toY, surface);
	player->Show(playerX, playerY, surface);

	SDL_Flip(surface);
}
