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


#Ajouter un .exe ou .deb/.appimage quand on compile
add_executable(Jeu_De_Quetes main.cpp)

#ajout du module graphique à Jeu_De_Quetes
target_link_libraries(Jeu_De_Quetes PRIVATE sfml-graphics sfml-window sfml-system)

