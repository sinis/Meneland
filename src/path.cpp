///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 16.04.2010
// Data modyfikacji: 16.04.2010
// Opis: Plik zawiera implementacjê klasy odpowiedzialnej za obs³ugê ¶cie¿ki
//  dostêpu do folderu roboczego.
///////////////////////////////////////////////////////////////////////////////

#include "path.h"

#ifdef linux
	#include <unistd.h>
#elif defined _WIN32
	#define WIN32_LEAN_AND_MEAN
	#include <windows.h>
#endif

// GetCWD /////////////////////////////////////////////////////////////////////
// Opis:
//  Funkcja ustala ¶cie¿kê do aktualnego folderu roboczego i zwraca j±.
// Zwraca:
//  std::string - ¶cie¿ka do folderu roboczego.
std::string Path::GetCWD()
{
	char cwd[256];

#ifdef linux
	getcwd(cwd, sizeof(cwd));
#elif defined _WIN32
	GetModuleFileName(0, cwd, sizeof(cwd));
#endif

	return std::string(cwd);
}
