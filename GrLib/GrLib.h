#ifndef STL_GrLib
#define STL_GrLib

#include <SFML/Graphics.hpp>
#include "../vectors/vector.h"
#include "../vectors/color.h"
#include "../button.h"

const int kWidthWindow  = 400;
const int kHeightWindow = 300;

// const int kArrowLength = 25;
const int kHandCoeff = 7;

class GraphicsCtx
{
public:
    sf::RenderWindow window;

    GraphicsCtx ();

};

void DrawVector    (Vector& vector, GraphicsCtx& ctx);
void DrawButton    (const Button& button, GraphicsCtx& ctx);

bool IsWindowOpen          (GraphicsCtx& ctx);
void CheckEventCloseWindow (GraphicsCtx& ctx);
void DisplayWindow         (GraphicsCtx& ctx);
void CleanWindow           (GraphicsCtx& ctx);

#endif /* STL_GrLib */