///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 16.04.2010
// Data modyfikacji: 16.04.2010
// Opis: Plik zawiera deklarację klasy obsługującej aktualną ścieżkę do folderu
//  roboczego. (właściwie to bez sensu tworzyć nową klasę, ale nie chce mi
//  się męczyć z funkcjami)
///////////////////////////////////////////////////////////////////////////////

#ifndef _PATH_H_
#define _PATH_H_

#include <string>

class Path
{
public:
	static std::string GetCWD();
};

#endif // _PATH_H_ ////////////////////////////////////////////////////////////
