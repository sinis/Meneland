///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 16.04.2010
// Data modyfikacji: 9.05.2010
// Opis: Plik zawiera implementację klasy odpowiedzialnej za obsługę ścieżki
//  dostępu do folderu roboczego.
///////////////////////////////////////////////////////////////////////////////

#include "path.h"

#ifdef linux
	#include <unistd.h>
#elif defined _WIN32
	#include <direct.h>
#endif

// GetCWD /////////////////////////////////////////////////////////////////////
// Opis:
//  Funkcja ustala ścieżkę do aktualnego folderu roboczego i zwraca ją.
// Zwraca:
//  std::string - ścieżka do folderu roboczego.
std::string Path::GetCWD()
{
	char cwd[256];

#ifdef linux
	getcwd(cwd, sizeof(cwd));
#elif defined _WIN32
	_getcwd(cwd, sizeof(cwd));
#endif

	return std::string(cwd);
}
