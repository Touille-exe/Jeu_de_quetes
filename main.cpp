//
// Created by Touille on 20/04/2026.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ecran_quete.hpp"
#include "Menu_demarrage.hpp"
#include "Random.hpp"
#include "FichierCsv.hpp"


bool startQueteConsole = true;

int main() {
    // 1. Initialisation de la fenêtre
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Jeu de Quetes");
    // 1. Charger l'image depuis le fichier
    int miaou = aleatoire(1,4);
    std::string add_icone;
    if (miaou == 1) {
        add_icone = "assets/chat1.jpg";
    } else if (miaou == 2) {
        add_icone = "assets/chat2.jpg";
    } else if (miaou == 3) {
        add_icone = "assets/chat3.jpg";
    } else {
        add_icone = "assets/chat4.jpg";
    }

    sf::Image icone;
    if (!icone.loadFromFile(add_icone)) {
        // Si l'image ne charge pas, on affiche une erreur, mais le jeu continue
        std::cerr << "Impossible de charger l'icone !" << std::endl;
    } else {
        // 2. Appliquer l'icone à la fenêtre
        // .getPixelsPtr() donne les données brutes de l'image
        // .getSize().x et .y donnent les dimensions
        window.setIcon(icone.getSize().x, icone.getSize().y, icone.getPixelsPtr());
    }

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
                if (event.key.code == sf::Keyboard::Space) {
                    etat = "quete_console";
                }
            }
            if (etat == "quete_console" && event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    std::cout << "espace" << std::endl;
                }
                if (event.key.code == sf::Keyboard::Escape) {
                    etat = "menu_demarrage";
                    startQueteConsole = true;
                }
            }
        }

        // 4. Mise à jour de la logique (Update)
        // C'est ici qu'on calculera les déplacements, les combats, etc.

        // 5. Affichage (Render)
        window.clear(sf::Color::Black);// Étape A : On efface l'écran avec du noir


        if (etat == "quete_console") {
            if (startQueteConsole) {
                DebutQueteConsole(startQueteConsole);
            }
            window.clear(sf::Color::Green);
            dessiner_QueteConsole(window);
        }
        if (etat == "menu_demarrage") {
            dessinerMenu(window);
        }

        // Étape B : C'est ici qu'on dessinera nos Gobelins, Orques et le décor !

        window.display(); // Étape C : On affiche le nouvel écran au joueur
    }

    return 0;
}
