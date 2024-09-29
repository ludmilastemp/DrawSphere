#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "tests/testSimple2D.h"
#include "tests/testSimple3D.h"
#include "tests/testFollowMouse.h"
#include "tests/testButtonControl.h"

// ВЕЗДЕ const&

int main()
{
    printf ("Start\n");
    int i = 0;

    GraphicsCtx ctx {};

    while (IsWindowOpen(ctx))
    {
        i++;
        if (i == 2) return 0;

        CheckEventCloseWindow (ctx);
        CleanWindow (ctx);

        // TestSimple2D (ctx);
        // TestSimple3D (ctx);
        // FollowMouseVector (ctx);
        // FollowMouseSphere (ctx);

        TestButtonControl (ctx);

        DisplayWindow(ctx);
    }

    return 0;
}

