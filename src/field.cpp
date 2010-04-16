///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 16.04.2010
// Opis: Implementacja obs�ugi pola mapy.
///////////////////////////////////////////////////////////////////////////////

#include "field.h"
#include <string>
#include "path.h"

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

	this->SetFieldType(type);
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
// Parametr:
//  - surface: SDL_Surface* - powierzchnia przekazywana obiektowi.
// Opis:
//  Funkcja przekazuje obs�ug� objectowi. Po wszystkim usuwa go.
void Field::HandleObject(SDL_Surface* surface)
{
	if (object)
	{
		object->Handling(surface);
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

// SetFieldType ///////////////////////////////////////////////////////////////
// Parametr:
//  - _type: FieldType - typ pola.
// Opis:
//  Funkcja �aduje dane pola.
void Field::SetFieldType(FieldType _type)
{
	std::string fileName = Path::GetCWD() + "/data/";
	switch (_type)
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
		default:
			type = NoneField;
			return;
	}

	type = _type;
	this->SetImage(fileName.c_str());
}
