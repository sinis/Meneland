///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 5.04.2010
// Opis: Implementacja obiekt�w wyst�puj�cych w grze.
///////////////////////////////////////////////////////////////////////////////

#include "object.h"
#include <SDL/SDL_image.h>
#include "messagebox.h"

// Konstruktor ////////////////////////////////////////////////////////////////
// Parametr:
//  - type: ObjectType - typ objectu.
// Opis:
//  Funkcja konstruuje object na podstawie podanego typu.
Object::Object(ObjectType _type):
	objectImage(0), type(_type)
{
	SetObjectType(type);
}

// SetObjectType //////////////////////////////////////////////////////////////
// Parametr:
//  - _type: ObjectType - typ obiektu.
// Opis:
//  Funkcja ustala obiekt.
void Object::SetObjectType(ObjectType _type)
{
	if (objectImage) SDL_FreeSurface(objectImage);
	if (image) SDL_FreeSurface(image);

	// W zale�no�ci od typu obiekt ma dobierany odpowiedni opis, obraz i miniatur�.
	std::string sImage = "data/";
	std::string sThumb = "data/";

	switch (type)
	{
		case Gawith:
			sImage += "gawith.png";
			sThumb += "gawith-min.png";
			description = "Znalaz�e� tabak�... U�ywk� cz�sto spotykan� w r�norakich �rodowiskach,\n"
						  "od m�odzie�owych, przez kopalniach, a� po koneser�w. Dla jednych jest okazj�\n"
						  "do manifestowania swojej (nie)dojrza�o�ci, dla drugich po prostu konieczna,\n"
						  "a dla trzecich, bo j� lubi�.\n"
						  "Cz�sto w �yciu spotykaj� Ci� chwile zadumy, chwile, w kt�rych chcesz si�\n"
						  "odci�� na chwil� od wszystkiego, chwile s�abo�ci. Odpowiednio za�yta tabaka\n"
						  "mo�e Ci te chwile os�odzi�. W osamotnieniu da� u�miech. W s�abo�ci Azyl.\n"
						  "W zadumie \"�wie�o��\" umys�u.";
			break;
		case Lesny:
			sImage += "lesny.png";
			sThumb += "lesny-min.png";
			description = "O, patrz, znalaz�e� Le�ny Dzban. Wytw�r winopodobny, znany r�wnie� pod\n";
						  "nazw� \"jabol\". Zawarto�� siarki umo�liwia jego picie, a jednak jeste�\n";
						  "twardy i pijesz. Dlaczego? Mo�e ze wzgl�du na jego wyj�tkowo��. A mo�e\n";
						  "po prostu �al Ci wydanych pieni�dzy. Tak czy inaczej Le�ny spity\n";
						  "w �adny dzie� na ��ce dodaje �yciu kolor�w.";
			break;
		case Rosolek:
			sImage += "rosolek.png";
			sThumb += "rosolek-min.png";
			description = "Ros�. Potrawa jedzona zwykle podczas niedzielnych obiad�w. Jednym\n";
						  "smakuje bardziej, drugim mniej. Tak czy inaczej �wietnie rozgrzewa.\n";
						  "Jednak uwa�aj. Z mag� mo�na przesadzi�.\n\n";
						  "\"Leo�, wpierdalaj roso�ek.\"";
			break;
		case Komputer:
			sImage += "komputer.png";
			sThumb += "komputer-min.png";
			description = "Znalaz�e� komputer. Teraz mo�esz poszuka� koleg�w w internecie.\n";
						  "Kto wie? Mo�e znajd� si� jacy� menele w okolicy...";
			break;
		// Literki
		case H:
			sThumb += "H.png";
			image = "";
			break;
		case L:
			sThumb += "L.png";
			image = "";
			break;
		case M:
			sThumb += "M.png";
			image = "";
			break;
		case N:
			sThumb += "N.png";
			image = "";
			break;
		case O:
			sThumb += "O.png";
			image = "";
			break;
		case P:
			sThumb += "P.png";
			image = "";
			break;
		case R:
			sThumb += "R.png";
			image = "";
			break;
		case U:
			sThumb += "U.png";
			image = "";
			break;
		case W:
			sThumb += "W.png";
			image = "";
			break;
		case Y:
			sThumb += "Y.png";
			image = "";
			break;
		case Z:
			sThumb += "Z.png";
			image = "";
			break;
	}

	Visible::SetImage(sThumb.c_str());
	if (!sImage.empty())
		objectImage = IMG_Load(sImage.c_str())
}

// Handling ///////////////////////////////////////////////////////////////////
// Opis:
//  Funkcja odpowiada za zdarzenie gdy gracz wejdzie na podany obiekt.
//  Wy�wietla komunikat z opisem i obrazem obiektu.
void Object::Handling()
{
	// MessageBox::Show(description.c_str(), objectImage);
}