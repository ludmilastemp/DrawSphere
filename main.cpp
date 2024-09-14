#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "test.h"

// ВЕЗДЕ const&
// sphere
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

        TestQuick (ctx);
        // FollowMouseVector (ctx);
        // FollowMouseSphere (ctx);
        // ButtonControlSphere (ctx);

        DisplayWindow(ctx);
    }

    return 0;
}

