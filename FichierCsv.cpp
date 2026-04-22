//
// Created by Touille on 22/04/2026.
//
#include "FichierCsv.hpp"


std::string LectureCsv(int LigneDemandee, int ColoneDemandee, std::string nomFichier) {
    std::ifstream fichier(nomFichier);

    if (!fichier.is_open()) {
        return "Erreur : Fichier introuvable";
    }

    std::string ligne;
    int indexLigne = 0; // Compteur pour suivre où on en est

    while (std::getline(fichier, ligne)) {
        // Si on a atteint la ligne souhaitée
        if (indexLigne == LigneDemandee) {
            std::stringstream ss(ligne);
            std::string cellule;
            int indexColone = 0;

            // On découpe la ligne pour trouver la colonne
            while (std::getline(ss, cellule, ',')) {
                if (indexColone == ColoneDemandee) {
                    fichier.close();
                    return cellule; // On a trouvé la valeur !
                }
                indexColone++;
            }
            return "Erreur : Colonne hors limites";
        }
        indexLigne++;
    }

    fichier.close();
    return "Erreur : Ligne hors limites";
}