//
// Created by Touille on 22/04/2026.
//
#include "Ecran_quete.hpp"

void dessiner_QueteConsole(sf::RenderWindow& window) {
    sf::Font police;
    // Remplace "arial.ttf" par le nom d'une police que tu as téléchargée et mise dans ton dossier
    if (!police.loadFromFile("assets/fonts/Roboto_SemiCondensed-Regular.ttf")) {
        std::cerr << "Erreur : Impossible de charger la police !" << std::endl;
        return; // On arrête la fonction s'il n'y a pas de police
    }

    sf::Text titre;
    titre.setFont(police);                 // On lui donne la police
    titre.setString("Quete dans la console :");      // Le texte à afficher
    titre.setCharacterSize(50);            // Taille en pixels
    titre.setFillColor(sf::Color::Yellow); // Couleur du texte
    titre.setPosition(200, 100);           // Position (X, Y) sur l'écran (0,0 est en haut à gauche)

    sf::Text sousTitre;
    sousTitre.setFont(police);
    sousTitre.setString("L'affichage ne sert a rien mais la fenetre doit etre active pour les controles");
    sousTitre.setCharacterSize(40);
    sousTitre.setFillColor(sf::Color::Yellow);
    sousTitre.setPosition(200, 160);

    // 4. Dessiner les éléments sur la fenêtre
    window.draw(titre);
    window.draw(sousTitre);
}

void DebutQueteConsole(bool& startQueteConsole) {
    startQueteConsole = false;
    std::cout << "quete_ici" << std::endl;

}