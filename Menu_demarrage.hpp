#pragma once
#include <SFML/Graphics.hpp>

// On déclare la fonction.
// Le "&" (référence) est CRUCIAL : il dit de modifier la VRAIE fenêtre du jeu,
// pas d'en créer une copie invisible dans la mémoire.
void dessinerMenu(sf::RenderWindow& window);