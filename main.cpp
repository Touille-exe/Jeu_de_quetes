//
// Created by Touille on 20/04/2026.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu_demarrage.hpp"

int main() {
    // 1. Initialisation de la fenêtre
    sf::RenderWindow window(sf::VideoMode(800, 600), "Jeu de Quetes");
    std::cout << "Jeu lance" << std::endl;
    std::string etat("menu_demarrage");

    // 2. La Boucle de Jeu Principale
    while (window.isOpen()) {

        // 3. Gestion des évènements (Inputs du joueur)
        sf::Event event;
        while (window.pollEvent(event)) {                                                                // Gestion des inputs
            // Si le joueur clique sur la croix pour fermer
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (etat == "menu_demarrage" && event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
        }

        // 4. Mise à jour de la logique (Update)
        // C'est ici qu'on calculera les déplacements, les combats, etc.

        // 5. Affichage (Render)
        window.clear(sf::Color::Black); // Étape A : On efface l'écran avec du noir
        dessinerMenu(window);

        // Étape B : C'est ici qu'on dessinera nos Gobelins, Orques et le décor !

        window.display(); // Étape C : On affiche le nouvel écran au joueur
    }

    return 0;
}