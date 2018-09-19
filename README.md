# singleton

[![Build Status](https://travis-ci.org/rene-d/singleton.svg?branch=master)](https://travis-ci.org/rene-d/singleton)

Exemples et différentes techniques pour forcer l'initialiser d'un [singleton](https://en.wikipedia.org/wiki/Singleton_pattern) C++ dans une librairie.

1. démonstration de la "perte" du singleton
2. on charge tous les symboles dans l'exécutable
3. on utilise une cible [Object Library](https://cmake.org/cmake/help/v3.12/manual/cmake-buildsystem.7.html#id20)
4. on appelle une fonction définie dans le fichier avec le singleton
5. on utilise une variable définie dans le fichier avec le singleton

En conclusion, l'association du DP singleton et du DP [factory](https://en.wikipedia.org/wiki/Factory_method_pattern) requiert des bidouilles en C/C++.
