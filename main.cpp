//
// Created by Touille on 20/04/2026.
//
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // 1. Initialisation de la fenêtre
    sf::RenderWindow window(sf::VideoMode(800, 600), "Jeu de Quetes - Moteur v1.0");

    // 2. La Boucle de Jeu Principale
    while (window.isOpen()) {

        // 3. Gestion des évènements (Inputs du joueur)
        sf::Event event;
        while (window.pollEvent(event)) {
            // Si le joueur clique sur la croix pour fermer
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // 4. Mise à jour de la logique (Update)
        // C'est ici qu'on calculera les déplacements, les combats, etc.

        // 5. Affichage (Render)
        window.clear(sf::Color::Black); // Étape A : On efface l'écran avec du noir

        // Étape B : C'est ici qu'on dessinera nos Gobelins, Orques et le décor !

        window.display(); // Étape C : On affiche le nouvel écran au joueur
    }

    return 0;
}