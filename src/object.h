///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 6.04.2010
// Opis: Deklaracja klasy odpowiedzialnej za obiekty w grze.
///////////////////////////////////////////////////////////////////////////////

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "visible.h" // Klasa bazowa.
#include <string>

enum ObjectType
{
	Gawith,
	Lesny,
	Rosolek,
	Komputer,
	H, L, M, N, O, P, R, U, W, Y, Z // PROMHYLOWNZYOU
};

class Object: public Visible
{
public:
	Object(ObjectType _type);

	void Handling(); // Obs³uga objectu.

	void SetObjectType(ObjectType _type);
	ObjectType GetObjectType() const { return type; }

private:
	ObjectType type;
	std::string description; // Opis obiektu ustawiany w zale¿no¶ci od jego typu.
	SDL_Surface* objectImage; // Obraz obiektu.
};

#endif // _OBJECT_H_ //////////////////////////////////////////////////////////
