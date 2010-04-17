///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 17.04.2010
// Opis: Implementacja obsługi kamery.
///////////////////////////////////////////////////////////////////////////////

#include "camera.h"

// Konstruktor ////////////////////////////////////////////////////////////////
// Parametry:
//  - _map: const Map* - wskaźnik na mapę.
//  - _player: const Player* - wskaźnik na gracza.
//  - _surface: SDL_Surface* - powierzchnia gry.
// Opis:
//  Inicjalizuje wskaźniki wymagane do odrysowywania gry.
Camera::Camera(Map* _map, Player* _player, SDL_Surface* _surface):
	map(_map), player(_player), surface(_surface)
{}

// Show ///////////////////////////////////////////////////////////////////////
// Opis:
//  Pobiera informacje o położeniu gracza, oblicza, które pola mają zostać
//  wyświetlone, wyświetla je i umieszcza na nich gracza.
void Camera::Show()
{
	// Standardowo funkcja ma obliczać pola do wyświetlenia tak, żeby gracz
	// był na środku widocznej części mapy.
	// Jeśli gracz znajduje się przy którejś z krawędzi mapy, funkcja powinna
	// wyświetlić tyle pól ile może, a gracza gdzieś na nich.
	// Okno gry będzie w rozdzielczości 640x480 -> 16x12 pól.
	// Gracz będzie odrysowywany na polu 8x6 (7x5).
	// Współrzędne gracza powinny zostać wymnożone przez 40, ponieważ wyświetla
	// on tekstury wedle pikseli.

	int playerX = player->GetX();
	int playerY = player->GetY();
	int fromX;
	int fromY;

	// Jeśli można, pokazuje playera na środku mapy.
	/*if (playerX >= 7 && playerY >= 5 &&
		playerX <= map->GetWidth() - 8 && playerY <= map->GetHeight() - 5)
	{
		// Oblicza pola do wyświetlenia.
		fromX = playerX - 7;
		fromY = playerY - 5;

		// To samo z graczem.
		playerX = (fromX - playerX) * 40;
		playerY = (fromY - playerY) * 40;

	}*/ // Tego ifa trzeba rozbić.

	// Standardowe ustawienia dla pozycji X w zakresie.
	if (playerX >= 7 && playerX < map->GetWidth() - 8)
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
		fromX = map->GetWidth() - 16;
		playerX = (playerX - fromX) * 40;
	}

	// Standardowe ustawienia dla pozycji Y w zakresie.
	if (playerY >= 5 && playerY < map->GetHeight() - 6)
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
		fromY = map->GetHeight() - 12;
		playerY = (playerY - fromY) * 40;
	}

	// No ta... Nie wziąłem pod uwagę sytuacji, gdy rozmiar mapy jest mniejszy niż
	// 16x12.
	int toX = fromX + 16, toY = fromY + 12;
	if (toX >= map->GetWidth()) toX = map->GetWidth();
	if (toY >= map->GetHeight()) toY = map->GetHeight();
	if (fromX < 0)
	{
		fromX = 0;
		playerX = player->GetX() * 40;
	}
	if (fromY < 0)
	{
		fromY = 0;
		playerY = player->GetY() * 40;
	}

	// Przed wszystkim czyści ekran.
	SDL_FillRect(surface, &surface->clip_rect, SDL_MapRGB(surface->format, 0x00, 0x00, 0x00));

	// Wyświetlenie wszystkiego wedle ustawień.
	map->Show(fromX, fromY, toX, toY, surface);
	player->Show(playerX, playerY, surface);

	SDL_Flip(surface);
}
