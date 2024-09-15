#ifndef STL_GrLib
#define STL_GrLib

#include <SFML/Graphics.hpp>
#include "GrLibCtx.h"
#include "../objects/button.h"
#include "../vectors/vector.h"
#include "../color.h"

const int kWidthWindow  = 400;
const int kHeightWindow = 300;

// const int kArrowLength = 25;
const int kHandCoeff = 7;

void DrawVector (Vector& vector, GraphicsCtx& ctx);
// void DrawButton (const Button& button, GraphicsCtx& ctx);

bool IsWindowOpen          (GraphicsCtx& ctx);
void CheckEventCloseWindow (GraphicsCtx& ctx);
void DisplayWindow         (GraphicsCtx& ctx);
void CleanWindow           (GraphicsCtx& ctx);

#endif /* STL_GrLib */