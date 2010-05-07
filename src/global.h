///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 9.04.2010
// Data modyfikacji: 7.05.2010
// Opis: Plik zawiera globalne symbole dla klas.
///////////////////////////////////////////////////////////////////////////////

#ifndef _GLOBAL_H_
#define _GLOBAL_H_

enum Direction // Wykorzystywane przy określeniu ruchu i tekstury gracza.
{
	Down = 0,
	Up = 1,
	Left = 2,
	Right = 3
};

enum FieldType // Typ pola mapy.
{
	NoneField,
	Start = 's',
	Grass = ' ',
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
	Pies = 'p',
	Kaktus = 'c',
	Tymbark = 'a',
	Mandarynka = 'm',
	Soczek = 'j',
	Maluch = 'f',
	Ibanez = 'i',
	H = 'H', L = 'L', M = 'M', N = 'N', O = 'O', P = 'P', R = 'R',
	U = 'U', W = 'W', Y = 'Y', Z = 'Z' // PROMHYLOWNZYOU
};

Uint32 getpixel(SDL_Surface *surface, int x, int y);

#endif // _GLOBAL_H_ //////////////////////////////////////////////////////////
