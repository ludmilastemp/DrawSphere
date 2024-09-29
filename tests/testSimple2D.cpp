#include "testSimple2D.h"

#include <math.h>  

void PrintCyrcle (GraphicsCtx& ctx);
void PrintRect (GraphicsCtx& ctx);

void PrintCyrcle (GraphicsCtx& ctx)
{
    Vector v {250, 0.0};

    for (double i = 0; i > -M_PI * 2; i -= 0.01)
    {
        v.setPhi(i);

        CleanWindow (ctx);

        DrawVector (v, ctx);

        DisplayWindow(ctx);
    }
}

void PrintRect (GraphicsCtx& ctx)
{
    Vector v {-350, 250};

    for (int i = -350; i < 350; i++)
    {
        v.setX(i);

        CleanWindow (ctx);

        DrawVector (v, ctx);

        DisplayWindow(ctx);
    }

    for (int i = 250; i > -250; i--)
    {
        v.setY(i);

        CleanWindow (ctx);

        DrawVector (v, ctx);

        DisplayWindow(ctx);
    }

    for (int i = 350; i > -350; i--)
    {
        v.setX(i);

        CleanWindow (ctx);

        DrawVector (v, ctx);

        DisplayWindow(ctx);
    }

    for (int i = -250; i < 250; i++)
    {
        v.setY(i);

        CleanWindow (ctx);

        DrawVector (v, ctx);

        DisplayWindow(ctx);
    }
}

void TestSimple2D (GraphicsCtx& ctx)
{
    PrintCyrcle (ctx);
    PrintCyrcle (ctx);
    PrintCyrcle (ctx);
    PrintRect   (ctx);
}