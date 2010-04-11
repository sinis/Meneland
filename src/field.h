///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 10.04.2010
// Opis: Deklaracja klasy obs³uguj±cej pole.
///////////////////////////////////////////////////////////////////////////////

#ifndef _FIELD_H_
#define _FIELD_H_

#include "visible.h" // Klasa bazowa.
#include "object.h"

class Field: public Visible
{
public:
	Field(FieldType _type = NoneField, Object* _object = 0);
	~Field();

	FieldType GetFieldType() const { return type; }
	void SetFieldType(FieldType _type) { type = _type; }

	const Object* GetObject() const { return object; }
	void SetObject(const Object* _object) { object = object; }

	void HandleObject(SDL_Surface* surface);

	bool IsAvailable() const { return available; }
	void SetAvailable(bool _a) { available = _a; }

	void Show(int x, int y, SDL_Surface* surface); // Trzeba przes³oniæ. Je¶li jest przypisany object
	             // Wy¶wietla tak¿e jego.

private:
	FieldType type;
	Object* object;
	bool available; // Czy mo¿na na pole wej¶æ?
};

#endif // _FIELD_H_ ///////////////////////////////////////////////////////////
