cmake_minimum_required(VERSION 3.20)
#Version de CMake
project(Jeu_De_Quetes VERSION 1.0)
#Nom et version du jeu : Utilisés pour les variables de CMake

set(CMAKE_CXX_STANDARD 20)
# Version du language
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#forcer la version

set(BUILD_SHARED_LIBS FALSE)
#compile le programme avec les dll

include(FetchContent)
#active l'outil de CMake qui permet d'aller chercher du code sur internet
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.1
)
#prépare le téléchargement
FetchContent_MakeAvailable(SFML)
#lance le téléchargement et rend la bibliothèque disponible pour notre projet

# Variable des fichiers sources
set(SOURCES
        main.cpp
        Menu_demarrage.cpp
        Menu_demarrage.hpp
        Random.hpp
        Ecran_quete.hpp
        Ecran_quete.cpp
        FichierCsv.hpp
        FichierCsv.cpp
)


# --- GESTION DES RESSOURCES ---

# On définit le dossier source des ressources et le dossier de destination
set(ASSETS_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/assets")
set(ASSETS_DEST_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Commande pour copier le dossier assets lors de la compilation
file(COPY ${ASSETS_SOURCE_DIR} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Optionnel : S'assurer que si on modifie un fichier dans assets, il est recopié
add_custom_target(copy_assets ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${ASSETS_SOURCE_DIR} ${ASSETS_DEST_DIR}
        COMMENT "Copie des ressources vers le dossier de build..."
)

#Ajouter un .exe ou .deb/.appimage quand on compile
add_executable(Jeu_De_Quetes ${SOURCES})

#ajout du module graphique à Jeu_De_Quetes
target_link_libraries(Jeu_De_Quetes PRIVATE sfml-graphics sfml-window sfml-system)

