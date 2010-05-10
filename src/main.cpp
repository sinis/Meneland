///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 9.05.2010
// Opis: Ot imitacja gry.
///////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <iostream>
#include "meneland.h"
#include "path.h"

bool CheckCWD();

int main(int, char**)
{
	// W Linuksie wyst�puje problem gdy gra jest uruchamiana z po�o�enia
	// innego ni� po�o�enie gry. Trzeba to za�atwi�.
	if (!CheckCWD()) // W�a�ciwie to to powinno by� w Inicie Menelandu...
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
//  Funkcja sprawdza czy dost�pny jest plik map.txt.
// Zwraca:
//  - true - je�li plik jest dost�pny.
//  - false - je�li pliku nie ma.
bool CheckCWD()
{
	std::string map = Path::GetCWD() + "/data/map.txt";
	std::ifstream file(map.c_str());
	if (!file.is_open())
		return false;
	file.close();
	return true;
}
