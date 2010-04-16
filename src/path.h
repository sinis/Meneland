///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 16.04.2010
// Data modyfikacji: 16.04.2010
// Opis: Plik zawiera deklaracjê klasy obs³uguj±cej aktualn± ¶cie¿kê do folderu
//  roboczego. (w³a¶ciwie to bez sensu tworzyæ now± klasê, ale nie chce mi
//  siê mêczyæ z funkcjami)
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
