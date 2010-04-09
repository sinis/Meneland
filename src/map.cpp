///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 10.04.2010
// Opis: Implementacja obs³ugi mapy.
///////////////////////////////////////////////////////////////////////////////

#include "map.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <fstream>

// Konstruktor ////////////////////////////////////////////////////////////////
// Parametr:
//  - player: Player* - wska¼nik na obiekt gracza. Potrzebny aby ustawiæ jego
//   po³o¿enie.
// Opis:
//  Inicjalizuje mapê.
//  1. Otwiera plik z danymi mapy.
//  2. Pobiera z niego rozmiar mapy.
//  3. Tworzy pola mapy.
//  4. Pobiera dane pól mapy i kolejno je ustawia.
//  5. Ustawia pozycjê gracza.
Map::Map(Player* player)
{
	std::ifstream file("data/map.txt");
	file >> w >> h;
	file.ignore('\n');

	map = new Field*[w];
	for (int i = 0; i < w; i++)
		map[i] = new Field[h];

	char* buffer = new char[w];
	// Pêtla pobieraj±ca dane z pliku
	for (int i = 0; i < h; i++)
	{
		file.getline(buffer, w);

		// Pêtla ustawiaj±ca w³a¶ciwo¶ci pól.
		for (int j = 0; j < w; j++)
		{
			FieldType fieldType;
			ObjectType objectType = NoneObject;

			switch (buffer[j])
			{
				case (char) Player: filedType = Grass; palyer->SetX(i); player->SetY(j); break;
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

			map[i][j].SetFieldType(fieldType);
			if (objectType != NoneObject)
				map[i][j].SetObject(new Object(objectType));
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
