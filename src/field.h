///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 16.04.2010
// Opis: Deklaracja klasy obsługującej pole.
///////////////////////////////////////////////////////////////////////////////

#ifndef _FIELD_H_
#define _FIELD_H_

#include <SDL/SDL.h>
#include "visible.h" // Klasa bazowa.
#include "object.h"
#include "global.h"

class Field: public Visible
{
public:
	Field(FieldType _type = NoneField, Object* _object = 0);
	virtual ~Field();

	FieldType GetFieldType() const { return type; }
	void SetFieldType(FieldType _type);

	const Object* GetObject() const { return object; }
	void SetObject(Object* _object) { object = _object; }

	void HandleObject(SDL_Surface* surface);

	bool IsAvailable() const { return available; }
	void SetAvailable(bool _a) { available = _a; }

	void Show(int x, int y, SDL_Surface* surface); // Trzeba przesłonić. Jeśli jest przypisany object
	             // Wyświetla także jego.

private:
	FieldType type;
	Object* object;
	bool available; // Czy można na pole wejść?
};

#endif // _FIELD_H_ ///////////////////////////////////////////////////////////
