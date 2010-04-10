///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 10.04.2010
// Opis: Implementacja obs�ugi pola mapy.
///////////////////////////////////////////////////////////////////////////////

#include "field.h"
#include <string>

// Konstruktor ////////////////////////////////////////////////////////////////
// Parametry:
//  - type: FieldType - wskazuje na typ pola.
//  - object: Object* - wska�nik na obiekt z pola.
// Opis:
//  Na podstawie podanego typu konstruktor przypisuje polu odpowiedni obraz
//  oraz parametr, czy gracz mo�e wej�� na pole.
Field::Field(FieldType _type, Object* _object):
	type(_type), object(_object), available(false)
{
	if (type == NoneField) return;

	std::string fileName = "data/";
	switch (type)
	{
		case Grass:
			available = true;
			fileName += "grass.png";
			break;
		case Bush:
			available = false;
			fileName += "bush.png";
			break;
		case Exit:
			available = true;
			fileName += "exit.png";
			break;
	}

	this->SetImage(fileName.c_str());
}

// Destruktor /////////////////////////////////////////////////////////////////
// Opis:
//  Destruktor czy�ci pami�� po obiekcie. Je�li do pola zosta� przypisany
//  obiekt - usuwa go.
Field::~Field()
{
	if (object) delete object;
}

// HandleObject ///////////////////////////////////////////////////////////////
// Opis:
//  Funkcja przekazuje obs�ug� objectowi. Po wszystkim usuwa go.
void Field::HandleObject()
{
	if (object)
	{
		object->Handling();
		delete object;
		object = 0;
	}
}

// Show ///////////////////////////////////////////////////////////////////////
// Parametry:
//  - x, y: int - wsp�rz�dne.
//  - surface: SDL_Surface* - powierzchnia.
// Opis:
//  Funkcja odrysowywuje pole, a na nim przechowywany object (je�li posiada).
void Field::Show(int x, int y, SDL_Surface* surface)
{
	Visible::Show(x, y, surface);
	if (object) object->Show(x, y, surface);
}
