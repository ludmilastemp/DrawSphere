#ifndef STL_GrLib
#define STL_GrLib

#include <SFML/Graphics.hpp>
#include "vector.h"
#include "button.h"

const int kWidthWindow  = 400;
const int kHeightWindow = 300;

// const int kArrowLength = 25;
const int kHandCoeff = 7;

void DrawVector    (Vector& vector, sf::RenderWindow& window);
void DrawButton    (const Button& button, sf::RenderWindow& window);
void DisplayWindow (sf::RenderWindow& window);
void CleanWindow   (sf::RenderWindow& window);

#endif /* STL_GrLib */