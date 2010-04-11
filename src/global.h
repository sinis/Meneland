///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 9.04.2010
// Data modyfikacji: 10.04.2010
// Opis: Plik zawiera globalne symbole dla klas.
///////////////////////////////////////////////////////////////////////////////

#ifndef _GLOBAL_H_
#define _GLOBAL_H_

enum Direction // Wykorzystywane przy okre¶leniu ruchu i tekstury gracza.
{
	Down = 0,
	Up = 1,
	Left = 2,
	Right = 3
};

enum FieldType // Typ pola mapy.
{
	NoneField,
	Player = 'p',
	Grass = 'g',
	Bush = 'b',
	Exit = 'e'
};

enum ObjectType // Typ obiektu.
{
	NoneObject,
	Gawith = 't',
	Lesny = 'l',
	Rosolek = 'r',
	Komputer = 'k',
	H = 'H', L = 'L', M = 'M', N = 'N', O = 'O', P = 'P', R = 'R',
	U = 'U', W = 'W', Y = 'Y', Z = 'Z' // PROMHYLOWNZYOU
};

Uint32 getpixel(SDL_Surface *surface, int x, int y);

#endif // _GLOBAL_H_ //////////////////////////////////////////////////////////
