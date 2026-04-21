//
// Created by Touille on 21/04/2026.
//
#pragma once
#include <random>

// On crée une fonction qui simule un dé
inline int aleatoire(int min, int max) {
    // 1. Initialisation du moteur (une seule fois)
    // 'static' permet de ne pas réinitialiser le hasard à chaque appel
    static std::random_device rd;
    static std::mt19937 moteur(rd());

    // 2. Création de la plage (ex: entre 1 et 6)
    std::uniform_int_distribution<int> dist(min, max);

    // 3. On génère le nombre
    return dist(moteur);
}