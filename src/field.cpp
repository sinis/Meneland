///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 10.04.2010
// Opis: Implementacja obs³ugi pola mapy.
///////////////////////////////////////////////////////////////////////////////

#include "field.h"
#include <string>

// Konstruktor ////////////////////////////////////////////////////////////////
// Parametry:
//  - type: FieldType - wskazuje na typ pola.
//  - object: Object* - wska¼nik na obiekt z pola.
// Opis:
//  Na podstawie podanego typu konstruktor przypisuje polu odpowiedni obraz
//  oraz parametr, czy gracz mo¿e wej¶æ na pole.
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
//  Destruktor czy¶ci pamiêæ po obiekcie. Je¶li do pola zosta³ przypisany
//  obiekt - usuwa go.
Field::~Field()
{
	if (object) delete object;
}

// HandleObject ///////////////////////////////////////////////////////////////
// Opis:
//  Funkcja przekazuje obs³ugê objectowi. Po wszystkim usuwa go.
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
//  - x, y: int - wspó³rzêdne.
//  - surface: SDL_Surface* - powierzchnia.
// Opis:
//  Funkcja odrysowywuje pole, a na nim przechowywany object (je¶li posiada).
void Show(int x, int y, SDL_Surface* surface)
{
	Visible::Show(x, y, surface);
	if (object) object->Show(x, y, surface);
}
