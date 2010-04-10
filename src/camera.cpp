///////////////////////////////////////////////////////////////////////////////
// Projekt: Meneland
// Autor: Sinis
// Data utworzenia: 5.04.2010
// Data modyfikacji: 10.04.2010
// Opis: Implementacja obs³ugi kamery.
///////////////////////////////////////////////////////////////////////////////

#include "camera.h"

// Konstruktor ////////////////////////////////////////////////////////////////
// Parametry:
//  - _map: const Map* - wska¼nik na mapê.
//  - _player: const Player* - wska¼nik na gracza.
// Opis:
//  Inicjalizuje wska¼niki wymagane do odrysowywania gry.
Camera::Camera(const Map* _map, const Player* _player):
	map(_map), player(_player)
{}
