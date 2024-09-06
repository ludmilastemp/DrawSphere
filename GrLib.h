#ifndef STL_GrLib
#define STL_GrLib

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <unistd.h>
#include "vector.h"

const int WIDTH_WINDOW  = 400;
const int HEIGHT_WINDOW = 300;

void DrawVector (Vector vector, sf::RenderWindow& window);
void DisplayWindow (sf::RenderWindow& window);
void CleanWindow (sf::RenderWindow& window);

#endif /* STL_GrLib */