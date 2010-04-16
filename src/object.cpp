///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 16.04.2010
// Opis: Implementacja obiekt�w wyst�puj�cych w grze.
///////////////////////////////////////////////////////////////////////////////

#include "object.h"
#include <SDL/SDL_image.h>
#include <cstdlib>
#include "messagebox.h"
#include "path.h"

// Konstruktor ////////////////////////////////////////////////////////////////
// Parametr:
//  - type: ObjectType - typ objectu.
// Opis:
//  Funkcja konstruuje object na podstawie podanego typu.
Object::Object(ObjectType _type):
	type(_type), objectImage(0)
{
	SetObjectType(type);
}

// Destruktor /////////////////////////////////////////////////////////////////
// Opis:
//  Wywala objectImage.
Object::~Object()
{
	SDL_FreeSurface(objectImage);
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
	std::string sImage = Path::GetCWD() + "/data/";
	std::string sThumb = Path::GetCWD() + "/data/";

	switch (_type)
	{
		case Gawith:
			sImage += "gawith.png";
			sThumb += "gawith-min.png";
			description = "Znalaz�e� tabak�... U�ywk� cz�sto spotykan�\n"
						  "w r�norakich �rodowiskach, od m�odzie�owych,\n"
						  "przez kopalni�, a� po koneser�w. Dla jednych\n"
						  " jest okazj� do manifestowania swojej\n"
						  "(nie)dojrza�o�ci, dla drugich po prostu\n"
						  "konieczna, a dla trzecich, bo j� lubi�.\n"
						  "Cz�sto w �yciu spotykaj� Ci� chwile\n"
						  "zadumy, chwile, w kt�rych chcesz si�\n"
						  "odci�� na od wszystkiego, chwile s�abo�ci.\n"
						  "Odpowiednio za�yta tabaka mo�e Ci te chwile\n"
						  "os�odzi�. W osamotnieniu da� u�miech.\n"
						  "W s�abo�ci Azyl.\n"
						  "W zadumie \"�wie�o��\" umys�u.";
			break;
		case Lesny:
			sImage += "lesny.png";
			sThumb += "lesny-min.png";
			description = "O, patrz, znalaz�e� Le�ny Dzban. Wytw�r\n"
						  "winopodobny, znany r�wnie� pod nazw� \"jabol\".\n"
						  "Zawarto�� siarki umo�liwia jego picie,\n"
						  " a jednak jeste� twardy i pijesz. Dlaczego?\n"
						  "Mo�e ze wzgl�du na jego wyj�tkowo��. A mo�e\n"
						  "po prostu �al Ci wydanych pieni�dzy.\n"
						  "Tak czy inaczej Le�ny spity w �adny dzie�\n"
						  "na ��ce dodaje �yciu kolor�w.";
			break;
		case Rosolek:
			sImage += "rosolek.png";
			sThumb += "rosolek-min.png";
			description = "Ros�. Potrawa jedzona zwykle podczas niedzielnych\n"
						  "obiad�w. Jednym smakuje bardziej, drugim mniej.\n"
						  "Tak czy inaczej �wietnie rozgrzewa.\n"
						  "Jednak uwa�aj. Z mag� mo�na przesadzi�.\n"
						  "\"Leo�, wpierdalaj roso�ek.\"";
			break;
		case Komputer:
			sImage += "komputer.png";
			sThumb += "komputer-min.png";
			description = "Znalaz�e� komputer. Teraz mo�esz poszuka�\n"
						  "koleg�w w internecie. Kto wie? Mo�e znajd�\n"
						  "si� jacy� menele w okolicy...";
			break;
		// Literki
		case H:
			sThumb += "H.png";
			sImage = "";
			break;
		case L:
			sThumb += "L.png";
			sImage = "";
			break;
		case M:
			sThumb += "M.png";
			sImage = "";
			break;
		case N:
			sThumb += "N.png";
			sImage = "";
			break;
		case O:
			sThumb += "O.png";
			sImage = "";
			break;
		case P:
			sThumb += "P.png";
			sImage = "";
			break;
		case R:
			sThumb += "R.png";
			sImage = "";
			break;
		case U:
			sThumb += "U.png";
			sImage = "";
			break;
		case W:
			sThumb += "W.png";
			sImage = "";
			break;
		case Y:
			sThumb += "Y.png";
			sImage = "";
			break;
		case Z:
			sThumb += "Z.png";
			sImage = "";
			break;
		case NoneObject:
			break; // �eby kompilator nie krzycza�.
		default:
			type = NoneObject;
			return;
	}

	type = _type;
	Visible::SetImage(sThumb.c_str());
	if (!sImage.empty())
		objectImage = IMG_Load(sImage.c_str());
}

// Handling ///////////////////////////////////////////////////////////////////
// Parametr:
//  - surface: SDL_Surface* - powierzchnia, na kt�rej odrysowany b�dzie
//   MessageBox.
// Opis:
//  Funkcja odpowiada za zdarzenie gdy gracz wejdzie na podany obiekt.
//  Wy�wietla komunikat z opisem i obrazem obiektu.
void Object::Handling(SDL_Surface* surface)
{
	if (description.empty())
		return;

	MessageBox::Show(description, objectImage, surface);

	if (type == Komputer)
	{
		system("start http://promhyl.oz.pl/ | firefox http://promhyl.oz.pl/");
	}
}
