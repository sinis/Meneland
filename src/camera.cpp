///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 14.04.2010
// Opis: Implementacja obs�ugi kamery.
///////////////////////////////////////////////////////////////////////////////

#include "camera.h"

// Konstruktor ////////////////////////////////////////////////////////////////
// Parametry:
//  - _map: const Map* - wska�nik na map�.
//  - _player: const Player* - wska�nik na gracza.
//  - _surface: SDL_Surface* - powierzchnia gry.
// Opis:
//  Inicjalizuje wska�niki wymagane do odrysowywania gry.
Camera::Camera(Map* _map, Player* _player, SDL_Surface* _surface):
	map(_map), player(_player), surface(_surface)
{}

// Show ///////////////////////////////////////////////////////////////////////
// Opis:
//  Pobiera informacje o po�o�eniu gracza, oblicza, kt�re pola maj� zosta�
//  wy�wietlone, wy�wietla je i umieszcza na nich gracza.
void Camera::Show()
{
	// Standardowo funkcja ma oblicza� pola do wy�wietlenia tak, �eby gracz
	// by� na �rodku widocznej cz�ci mapy.
	// Je�li gracz znajduje si� przy kt�rej� z kraw�dzi mapy, funkcja powinna
	// wy�wietli� tyle p�l ile mo�e, a gracza gdzie� na nich.
	// Okno gry b�dzie w rozdzielczo�ci 640x480 -> 16x12 p�l.
	// Gracz b�dzie odrysowywany na polu 8x6 (7x5).
	// Wsp�rz�dne gracza powinny zosta� wymno�one przez 40, poniewa� wy�wietla
	// on tekstury wedle pikseli.

	int playerX = player->GetX();
	int playerY = player->GetY();
	int fromX;
	int fromY;

	// Je�li mo�na, pokazuje playera na �rodku mapy.
	/*if (playerX >= 7 && playerY >= 5 &&
		playerX <= map->GetWidth() - 8 && playerY <= map->GetHeight() - 5)
	{
		// Oblicza pola do wy�wietlenia.
		fromX = playerX - 7;
		fromY = playerY - 5;

		// To samo z graczem.
		playerX = (fromX - playerX) * 40;
		playerY = (fromY - playerY) * 40;

	}*/ // Tego ifa trzeba rozbi�.

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

	// No ta... Nie wzi��em pod uwag� sytuacji, gdy rozmiar mapy jest mniejszy ni�
	// 16x8.
	int toX = fromX + 15, toY = fromY + 7;
	if (toX >= map->GetWidth()) toX = map->GetWidth();
	if (toY >= map->GetHeight()) toY = map->GetHeight();

	// Przed wszystkim czy�ci ekran.
	SDL_FillRect(surface, &surface->clip_rect, SDL_MapRGB(surface->format, 0x00, 0x00, 0x00));

	// Wy�wietlenie wszystkiego wedle ustawie�.
	map->Show(fromX, fromY, toX, toY, surface);
	player->Show(playerX, playerY, surface);

	SDL_Flip(surface);
}
