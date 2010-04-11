///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 9.04.2010
// Data modyfikacji: 11.04.2010
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

/*
 * Return the pixel value at (x, y)
 * NOTE: The surface must be locked before calling this!
 */
Uint32 getpixel(SDL_Surface *surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        return *p;

    case 2:
        return *(Uint16 *)p;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;

    case 4:
        return *(Uint32 *)p;

    default:
        return 0;       /* shouldn't happen, but avoids warnings */
    }
}

#endif // _GLOBAL_H_ //////////////////////////////////////////////////////////
