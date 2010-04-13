///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 13.04.2010
// Opis: Ot imitacja gry.
///////////////////////////////////////////////////////////////////////////////

#include "meneland.h"

int main()
{
	Meneland* meneland = new Meneland;
	if (!meneland->Init())
	{
		delete meneland;
		return -1;
	}
	return meneland->Execute();
}
