///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 16.04.2010
// Data modyfikacji: 16.04.2010
// Opis: Plik zawiera deklaracj� klasy obs�uguj�cej aktualn� �cie�k� do folderu
//  roboczego. (w�a�ciwie to bez sensu tworzy� now� klas�, ale nie chce mi
//  si� m�czy� z funkcjami)
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
