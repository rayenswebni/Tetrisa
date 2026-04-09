#include <raylib.h>
#include "game.h"

double lasteUpdateTime = 0;

bool EventTriggerred(double interval){
    if (GetTime() - lasteUpdateTime >= interval){
        lasteUpdateTime = GetTime();
        return true;
    }
    return false;
}

int main()  
{
    const Color darkRed = {58, 11, 0, 255};
    
    constexpr int screenWidth = 600;
    constexpr int screenHeight = 620;

    InitWindow(screenWidth, screenHeight, "tetris!");
    SetTargetFPS(120);

    Font font = LoadFontEx("resources/zorque.ttf", 64, 0, 0);


    Game game = Game();

    while (!WindowShouldClose())
    {      
        UpdateMusicStream(game.music);  
        game.HandleInput();
        
        if(EventTriggerred(0.5)){
            game.MoveBlockDown();
        }

        BeginDrawing();
            ClearBackground(darkRed);
            game.Draw(font);
        EndDrawing();
    }
    
    CloseWindow();
}