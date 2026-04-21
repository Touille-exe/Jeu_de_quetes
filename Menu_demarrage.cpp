//
// Created by Touille on 20/04/2026.
//
#include "Menu_demarrage.hpp"
#include <iostream>

// Voici le code réel de la fonction promise dans le .hpp
void dessinerMenu(sf::RenderWindow& window) {

    // 1. Charger une police d'écriture (Font)
    sf::Font police;
    // Remplace "arial.ttf" par le nom d'une police que tu as téléchargée et mise dans ton dossier
    if (!police.loadFromFile("assets/fonts/Roboto_SemiCondensed-Regular.ttf")) {
        std::cerr << "Erreur : Impossible de charger la police !" << std::endl;
        return; // On arrête la fonction s'il n'y a pas de police
    }

    // 2. Créer le texte du Titre
    sf::Text titre;
    titre.setFont(police);                 // On lui donne la police
    titre.setString("JEU DE QUETES");      // Le texte à afficher
    titre.setCharacterSize(50);            // Taille en pixels
    titre.setFillColor(sf::Color::Yellow); // Couleur du texte
    titre.setPosition(200, 100);           // Position (X, Y) sur l'écran (0,0 est en haut à gauche)

    // 4. Dessiner les éléments sur la fenêtre
    window.draw(titre);
}