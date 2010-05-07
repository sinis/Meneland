///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 7.05.2010
// Opis: Implementacja obsługi mapy.
///////////////////////////////////////////////////////////////////////////////

#include "map.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <fstream>
#include "path.h"

// Konstruktor ////////////////////////////////////////////////////////////////
// Parametr:
//  - playerX, playerY: int& - położenie gracza.
// Opis:
//  Inicjalizuje mapę.
//  1. Otwiera plik z danymi mapy.
//  2. Pobiera z niego rozmiar mapy.
//  3. Tworzy pola mapy.
//  4. Pobiera dane pól mapy i kolejno je ustawia.
//  5. Ustawia pozycję gracza.
Map::Map(int& playerX, int& playerY)
{
	std::ifstream file((Path::GetCWD() + "/data/map.txt").c_str());
	file >> w >> h;
	file.ignore();

	// Tworzy matrycę pól o rozmiarze mapy.
	// map[x][y] (w = 4; h = 3)
	// map -> x 0 1 2 3
	//          v v v v
	//        y 0 0 0 0
	//          1 1 1 1
	//          2 2 2 2

	map = new Field*[w];
	for (int i = 0; i < w; i++)
		map[i] = new Field[h];

	char* buffer = new char[w+1];
	// Pętla pobierająca dane z pliku
	for (int i = 0; i < h; i++)
	{
		file.getline(buffer, w+1);

		// Pętla ustawiająca właściwości pól.
		for (int j = 0; j < w; j++)
		{
			FieldType fieldType;
			ObjectType objectType = NoneObject;

			switch (buffer[j])
			{
				case (char) Start: fieldType = Grass; playerX = j; playerY = i; /*palyer->SetX(i); player->SetY(j);*/ break;
				case (char) Grass: fieldType = Grass; break;
				case (char) Bush: fieldType = Bush; break;
				case (char) Exit: fieldType = Exit; break;
				case (char) Gawith: fieldType = Grass; objectType = Gawith; break;
				case (char) Lesny: fieldType = Grass; objectType = Lesny; break;
				case (char) Rosolek: fieldType = Grass; objectType = Rosolek; break;
				case (char) Komputer: fieldType = Grass; objectType = Komputer; break;
				case (char) Pies: fieldType = Grass; objectType = Pies; break;
				case (char) Kaktus: fieldType = Grass; objectType = Kaktus; break;
				case (char) Tymbark: fieldType = Grass; objectType = Tymbark; break;
				case (char) Mandarynka: fieldType = Grass; objectType = Mandarynka; break;
				case (char) Soczek: fieldType = Grass; objectType = Soczek; break;
				case (char) Maluch: fieldType = Grass; objectType = Maluch; break;
				case (char) Ibanez: fieldType = Grass; objectType = Ibanez; break;
				case (char) H: fieldType = Grass; objectType = H; break;
				case (char) L: fieldType = Grass; objectType = L; break;
				case (char) M: fieldType = Grass; objectType = M; break;
				case (char) N: fieldType = Grass; objectType = N; break;
				case (char) O: fieldType = Grass; objectType = O; break;
				case (char) P: fieldType = Grass; objectType = P; break;
				case (char) R: fieldType = Grass; objectType = R; break;
				case (char) U: fieldType = Grass; objectType = U; break;
				case (char) W: fieldType = Grass; objectType = W; break;
				case (char) Y: fieldType = Grass; objectType = Y; break;
				case (char) Z: fieldType = Grass; objectType = Z; break;
			}

			map[j][i].SetFieldType(fieldType);
			if (objectType != NoneObject)
				map[j][i].SetObject(new Object(objectType));
		}
	}
	delete [] buffer;
	file.close();
}

// Destruktor /////////////////////////////////////////////////////////////////
// Opis:
//  Czyści pamięć po obiekcie - usuwa fieldy.
Map::~Map()
{
	for (int i = 0; i < w; i++)
		delete [] map[i];
	delete [] map;
}

// Show ///////////////////////////////////////////////////////////////////////
// Parametry:
//  - fromX, fromY: int - współrzędne pola, od którego zacząć wyświetlanie
//  - toX, toY: int - współrzędne pola, na którym zakończyć wyświetlanie.
//  - surface: SDL_Surface* - powierzchnia, na której wyświetlić obraz.
// Opis:
//  Funkcja wyświetla zakres pól na ekranie.
void Map::Show(int fromX, int fromY, int toX, int toY, SDL_Surface* surface)
{
	// Każde pole ma wymiary 40x40px.
	// Przesunięcie każdego pola x = (i - fromX) * 40
	//                           y = (j - fromY) * 40
	int xOffset = 0;
	int yOffset = 0;
	for (int i = fromX; i < toX; i++)
	{
		xOffset = (i - fromX) * 40;

		for (int j = fromY; j < toY; j++)
		{
			yOffset = (j - fromY) * 40;

			map[i][j].Show(xOffset, yOffset, surface);
		}
	}
}

// IsMovePossible /////////////////////////////////////////////////////////////
// Parametry:
//  - x, y: int - położenie gracza
//  - dir: Direction - kierunek, w którym gracz chce się udać.
// Opis:
//  Na podstawie podanych parametrów funkcja sprawdza czy ruch gracza jest
//  możliwy do zrealizowania.
// Zwraca:
//  - true - jeśli tak.
//  - false - w przeciwnym wypadku.
bool Map::IsMovePossible(int x, int y, Direction dir)
{
	// Ruch jest możliwy jeśli pole, na które gracz chce wejść istnieje, oraz
	// jest oznaczone jako available.

	switch (dir)
	{
		case Up:
			y--;
			if (y < 0) return false; // Pole nie istnieje.
			break;
		case Down:
			y++;
			if (y >= h) return false; // Pole nie istnieje.
			break;
		case Left:
			x--;
			if (x < 0) return false; // Pole nie istnieje.
			break;
		case Right:
			x++;
			if (x >= w) return false; // Pole nie istnieje.
			break;
	}

	// Jeśli wykonanie doszło tutaj - ruch jest możliwy jeśli pole docelowe
	// jest oznaczone jako available.
	return map[x][y].IsAvailable();
}

// MoveHandling ///////////////////////////////////////////////////////////////
// Parametry:
//  - x, y: int - położenie gracza.
//  - surface: SDL_Surface* - powierzchnia przekazywana do obiektu.
// Opis:
//  Funkcja przekazuje wykonanie do funkcji obsługi pola.
// Zwraca:
//  - Exit - jeśli gracz wszedł na pole wyjścia.
//  - NoneField - w innym wypadku.
FieldType Map::MoveHandling(int x, int y, SDL_Surface* surface)
{
	if (map[x][y].GetFieldType() == Exit)
		return Exit;

	map[x][y].HandleObject(surface);

	return NoneField;
}
