///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 16.04.2010
// Opis: Implementacja obs³ugi mapy.
///////////////////////////////////////////////////////////////////////////////

#include "map.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <fstream>
#include "path.h"

// Konstruktor ////////////////////////////////////////////////////////////////
// Parametr:
//  - playerX, playerY: int& - po³o¿enie gracza.
// Opis:
//  Inicjalizuje mapê.
//  1. Otwiera plik z danymi mapy.
//  2. Pobiera z niego rozmiar mapy.
//  3. Tworzy pola mapy.
//  4. Pobiera dane pól mapy i kolejno je ustawia.
//  5. Ustawia pozycjê gracza.
Map::Map(int& playerX, int& playerY)
{
	std::ifstream file((Path::GetCWD() + "/data/map.txt").c_str());
	file >> w >> h;
	file.ignore();

	// Tworzy matrycê pól o rozmiarze mapy.
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
	// Pêtla pobieraj±ca dane z pliku
	for (int i = 0; i < h; i++)
	{
		file.getline(buffer, w+1);

		// Pêtla ustawiaj±ca w³a¶ciwo¶ci pól.
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
//  Czy¶ci pamiêæ po obiekcie - usuwa fieldy.
Map::~Map()
{
	for (int i = 0; i < w; i++)
		delete [] map[i];
	delete [] map;
}

// Show ///////////////////////////////////////////////////////////////////////
// Parametry:
//  - fromX, fromY: int - wspó³rzêdne pola, od którego zacz±æ wy¶wietlanie
//  - toX, toY: int - wspó³rzêdne pola, na którym zakoñczyæ wy¶wietlanie.
//  - surface: SDL_Surface* - powierzchnia, na której wy¶wietliæ obraz.
// Opis:
//  Funkcja wy¶wietla zakres pól na ekranie.
void Map::Show(int fromX, int fromY, int toX, int toY, SDL_Surface* surface)
{
	// Ka¿de pole ma wymiary 40x40px.
	// Przesuniêcie ka¿dego pola x = (i - fromX) * 40
	//                           y = (j - fromY) * 40
	int xOffset = 0;
	int yOffset = 0;
	for (int i = fromX; i < toX; i++)
	{
		xOffset = (i - fromY) * 40;

		for (int j = fromY; j < toY; j++)
		{
			yOffset = (j - fromX) * 40;

			map[i][j].Show(xOffset, yOffset, surface);
		}
	}
}

// IsMovePossible /////////////////////////////////////////////////////////////
// Parametry:
//  - x, y: int - po³o¿enie gracza
//  - dir: Direction - kierunek, w którym gracz chce siê udaæ.
// Opis:
//  Na podstawie podanych parametrów funkcja sprawdza czy ruch gracza jest
//  mo¿liwy do zrealizowania.
// Zwraca:
//  - true - je¶li tak.
//  - false - w przeciwnym wypadku.
bool Map::IsMovePossible(int x, int y, Direction dir)
{
	// Ruch jest mo¿liwy je¶li pole, na które gracz chce wej¶æ istnieje, oraz
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

	// Je¶li wykonanie dosz³o tutaj - ruch jest mo¿liwy je¶li pole docelowe
	// jest oznaczone jako available.
	return map[x][y].IsAvailable();
}

// MoveHandling ///////////////////////////////////////////////////////////////
// Parametry:
//  - x, y: int - po³o¿enie gracza.
//  - surface: SDL_Surface* - powierzchnia przekazywana do obiektu.
// Opis:
//  Funkcja przekazuje wykonanie do funkcji obs³ugi pola.
// Zwraca:
//  - Exit - je¶li gracz wszed³ na pole wyj¶cia.
//  - NoneField - w innym wypadku.
FieldType Map::MoveHandling(int x, int y, SDL_Surface* surface)
{
	if (map[x][y].GetFieldType() == Exit)
		return Exit;

	map[x][y].HandleObject(surface);

	return NoneField;
}
