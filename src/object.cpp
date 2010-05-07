///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 7.05.2010
// Opis: Implementacja obiektów występujących w grze.
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

	// W zależności od typu obiekt ma dobierany odpowiedni opis, obraz i miniaturę.
	std::string sImage = Path::GetCWD() + "/data/";
	std::string sThumb = Path::GetCWD() + "/data/";

	switch (_type)
	{
		case Gawith:
			sImage += "gawith.png";
			sThumb += "gawith-min.png";
			description = "Znalazłeś tabakę... Używkę często spotykaną\n"
						  "w różnorakich środowiskach, od młodzieżowych,\n"
						  "przez kopalnię, aż po koneserów. Dla jednych\n"
						  " jest okazją do manifestowania swojej\n"
						  "(nie)dojrzałości, dla drugich po prostu\n"
						  "konieczna, a dla trzecich, bo ją lubią.\n"
						  "Często w życiu spotykają Cię chwile\n"
						  "zadumy, chwile, w których chcesz się\n"
						  "odciąć na od wszystkiego, chwile słabości.\n"
						  "Odpowiednio zażyta tabaka może Ci te chwile\n"
						  "osłodzić. W osamotnieniu dać uśmiech.\n"
						  "W słabości Azyl.\n"
						  "W zadumie \"świeżość\" umysłu.";
			break;
		case Lesny:
			sImage += "lesny.png";
			sThumb += "lesny-min.png";
			description = "O, patrz, znalazłeś Leśny Dzban. Wytwór\n"
						  "winopodobny, znany również pod nazwą \"jabol\".\n"
						  "Zawartość siarki umożliwia jego picie,\n"
						  " a jednak jesteś twardy i pijesz. Dlaczego?\n"
						  "Może ze względu na jego wyjątkowość. A może\n"
						  "po prostu żal Ci wydanych pieniędzy.\n"
						  "Tak czy inaczej Leśny spity w ładny dzień\n"
						  "na łące dodaje życiu kolorów.";
			break;
		case Rosolek:
			sImage += "rosolek.png";
			sThumb += "rosolek-min.png";
			description = "Rosół. Potrawa jedzona zwykle podczas niedzielnych\n"
						  "obiadów. Jednym smakuje bardziej, drugim mniej.\n"
						  "Tak czy inaczej świetnie rozgrzewa.\n"
						  "Jednak uważaj. Z magą można przesadzić.\n"
						  "\"Leoś, wpierdalaj rosołek.\"";
			break;
		case Komputer:
			sImage += "komputer.png";
			sThumb += "komputer-min.png";
			description = "Znalazłeś komputer. Teraz możesz poszukać\n"
						  "kolegów w internecie. Kto wie? Może znajdą\n"
						  "się jacyś menele w okolicy...";
			break;
		case Pies:
			sImage += "pies.png";
			sThumb += "pies-min.png";
			description = "A oto prawdziwy przyjaciel. Potrafi\n"
						  "kochać bez względu na wszystko.\n"
						  "To do szczęścia wystarczy.";
			break;
		case Kaktus:
			sImage += "kaktus.png";
			sThumb += "kaktus-min.png";
			description = "\"Zabiłeś go...\"\n  \n"
						  "\"Patrzcie! On ma czapeczkę!\"";
			break;
        case Tymbark:
            sImage += "tymbark.png";
            sThumb += "tymbark-min.png";
            description = "Lolwtf?!\n"
                          "\n  \n\"Twoje zdrowie!\"";
            break;
        case Mandarynka:
            sImage += "mandarynka.png";
            sThumb += "mandarynka-min.png";
            description = "\"Będzie miał czapeczkę...\"";
            break;
		case Soczek:
			sImage += "sok.png";
			sThumb += "sok-min.png";
			description = "Soczek jest zarombisty. Słodki\n"
						  "ale zarombisty.\n  \n"
						  "\"Chcesz?\"\n"
						  "\"Nie.\"\n"
						  "\"Albo daj.\"";
			break;
        case Maluch:
            sImage += "maluch.png";
            sThumb += "maluch-min.png";
            description = "Ach te czasy dzieciństwa...";
            break;
		case Ibanez:
			sImage += "ibanez.png";
			sThumb += "ibanez-min.png";
			description = "*brzdęk, brzdęk, brzdęk...*\n"
						  "\"Nikt jeszcze nie wie czy stare słońce\n"
						  "zarysuje nowy dzień...\"";
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
			break; // Żeby kompilator nie krzyczał.
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
//  - surface: SDL_Surface* - powierzchnia, na której odrysowany będzie
//   MessageBox.
// Opis:
//  Funkcja odpowiada za zdarzenie gdy gracz wejdzie na podany obiekt.
//  Wyświetla komunikat z opisem i obrazem obiektu.
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
