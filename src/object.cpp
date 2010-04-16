///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 16.04.2010
// Opis: Implementacja obiektów wystêpuj±cych w grze.
///////////////////////////////////////////////////////////////////////////////

#include "object.h"
#include <SDL/SDL_image.h>
#include <cstdlib>
#include "messagebox.h"

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

	// W zale¿no¶ci od typu obiekt ma dobierany odpowiedni opis, obraz i miniaturê.
	std::string sImage = "data/";
	std::string sThumb = "data/";

	switch (_type)
	{
		case Gawith:
			sImage += "gawith.png";
			sThumb += "gawith-min.png";
			description = "Znalaz³e¶ tabakê... U¿ywkê czêsto spotykan± w ró¿norakich ¶rodowiskach,\n"
						  "od m³odzie¿owych, przez kopalniach, a¿ po koneserów. Dla jednych jest okazj±\n"
						  "do manifestowania swojej (nie)dojrza³o¶ci, dla drugich po prostu konieczna,\n"
						  "a dla trzecich, bo j± lubi±.\n"
						  "Czêsto w ¿yciu spotykaj± Ciê chwile zadumy, chwile, w których chcesz siê\n"
						  "odci±æ na chwilê od wszystkiego, chwile s³abo¶ci. Odpowiednio za¿yta tabaka\n"
						  "mo¿e Ci te chwile os³odziæ. W osamotnieniu daæ u¶miech. W s³abo¶ci Azyl.\n"
						  "W zadumie \"¶wie¿o¶æ\" umys³u.";
			break;
		case Lesny:
			sImage += "lesny.png";
			sThumb += "lesny-min.png";
			description = "O, patrz, znalaz³e¶ Le¶ny Dzban. Wytwór winopodobny, znany równie¿ pod\n"
						  "nazw± \"jabol\". Zawarto¶æ siarki umo¿liwia jego picie, a jednak jeste¶\n"
						  "twardy i pijesz. Dlaczego? Mo¿e ze wzglêdu na jego wyj±tkowo¶æ. A mo¿e\n"
						  "po prostu ¿al Ci wydanych pieniêdzy. Tak czy inaczej Le¶ny spity\n"
						  "w ³adny dzieñ na ³±ce dodaje ¿yciu kolorów.";
			break;
		case Rosolek:
			sImage += "rosolek.png";
			sThumb += "rosolek-min.png";
			description = "Rosó³. Potrawa jedzona zwykle podczas niedzielnych obiadów. Jednym\n"
						  "smakuje bardziej, drugim mniej. Tak czy inaczej ¶wietnie rozgrzewa.\n"
						  "Jednak uwa¿aj. Z mag± mo¿na przesadziæ.\n\n"
						  "\"Leo¶, wpierdalaj roso³ek.\"";
			break;
		case Komputer:
			sImage += "komputer.png";
			sThumb += "komputer-min.png";
			description = "Znalaz³e¶ komputer. Teraz mo¿esz poszukaæ kolegów w internecie.\n"
						  "Kto wie? Mo¿e znajd± siê jacy¶ menele w okolicy...";
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
			break; // ¯eby kompilator nie krzycza³.
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
//  - surface: SDL_Surface* - powierzchnia, na której odrysowany bêdzie
//   MessageBox.
// Opis:
//  Funkcja odpowiada za zdarzenie gdy gracz wejdzie na podany obiekt.
//  Wy¶wietla komunikat z opisem i obrazem obiektu.
void Object::Handling(SDL_Surface* surface)
{
	MessageBox::Show(description, objectImage, surface);

	if (type == Komputer)
	{
		system("start http://promhyl.oz.pl/ | firefox http://promhyl.oz.pl/");
	}
}
