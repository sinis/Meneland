///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 17.04.2010
// Opis: Ot imitacja gry.
///////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <iostream>
#include "meneland.h"
#include "path.h"

bool CheckCWD();

int main()
{
	// W Linuksie występuje problem gdy gra jest uruchamiana z położenia
	// innego niż położenie gry. Trzeba to załatwić.
	if (!CheckCWD()) // Właściwie to to powinno być w Inicie Menelandu...
	{
		std::cerr << "Nie mozna odpalic gry z polozenia, w ktorym nie sa dostepne jej pliki.\n";
		std::cerr << "Wejdz do katalogu gry i stamtad ja uruchom.\n";
		return -1;
	}

	Meneland* meneland = new Meneland;
	if (!meneland->Init())
	{
		delete meneland;
		return -1;
	}
	return meneland->Execute();
}

// CheckCWD ///////////////////////////////////////////////////////////////////
// Opis:
//  Funkcja sprawdza czy dostępny jest plik map.txt.
// Zwraca:
//  - true - jeśli plik jest dostępny.
//  - false - jeśli pliku nie ma.
bool CheckCWD()
{
	std::string map = Path::GetCWD() + "/data/map.txt";
	std::ifstream file(map.c_str());
	if (!file)
		return false;
	file.close();
	return true;
}
