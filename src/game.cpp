#include "game.h"
#include <random>



Game::Game(){
    grid=Grid();
    blocks=GetAllBlocks();
    currentBlock=GetRandomBlock();
    nextBlock=GetRandomBlock();
    gameOver = false;
    score = 0;
    InitAudioDevice();
    music = LoadMusicStream("sounds/music.mp3");
    PlayMusicStream(music);
    rotateSound = LoadSound("sounds/rotate.mp3");
    clearSound = LoadSound("sounds/clear.mp3");

}

Game::~Game() {
    UnloadMusicStream(music);
    UnloadSound(rotateSound);
    UnloadSound(clearSound);
    CloseAudioDevice();
}   

Block Game::GetRandomBlock(){

    if(blocks.empty()){
        blocks=GetAllBlocks();
    }


    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> Game::GetAllBlocks(){
    return {
        IBlock(),
        JBlock(),
        LBlock(),
        OBlock(),
        SBlock(),
        TBlock(),
        ZBlock()
    };
}

void Game::Draw(Font font){

    DrawRectangleRounded({8, 8, 314, 604}, 0.08f, 6, {0, 0, 0, 60});
    DrawRectangleLinesEx({8, 8, 314, 604}, 2, {255, 255, 255, 40});

    DrawTextEx(font, "Score", {400, 10}, 38, 2, WHITE);
    char scoreText[10];
    sprintf(scoreText, "%d", score);
    Vector2 textsize = MeasureTextEx(font, scoreText, 38, 2);
    
    DrawRectangleRounded({360,50,170,60},0.3,6,darkRed2);
    DrawRectangleLinesEx({360,50,170,60}, 2, {255, 255, 255, 40});
    DrawTextEx(font, scoreText, {360+(170 - textsize.x)/2, 50+(60 - textsize.y)/4}, 38, 2, WHITE);



    DrawTextEx(font, "Next", {400, 175}, 38, 2, WHITE);
    DrawRectangleRounded({360,250,170,170},0.3,6,darkRed2);
    DrawRectangleLinesEx({360,250,170,170}, 2, {255, 255, 255, 40});
    nextBlock.Draw(320,280);

    
  

    grid.Draw();



    currentBlock.Draw(11,11);
    if(gameOver){
        DrawRectangle(0, 0, 600, 620, {0,0,0,150});
        DrawTextEx(font, "Game Over", {210, 200}, 38, 2, RED);
        DrawTextEx(font, "Press any key to restart", {150, 250}, 28, 2, WHITE);
    }
}











void Game::HandleInput(){
    int keyPressed = GetKeyPressed();
    if(gameOver && keyPressed !=0){
        gameOver = false;
        Reset();
    }
    else{    
        switch(keyPressed){
        case KEY_A:
        case KEY_LEFT:
        MoveBlockLeft();
        break;
        case KEY_D:
        case KEY_RIGHT:
        MoveBlockRight();
        break;
        case KEY_S:
        case KEY_DOWN:
        MoveBlockDown();
        UpdateScore(0,1);
        break;
        case KEY_UP:
        case KEY_SPACE:
        RotateBlock();
        break;
    }
}
}

void Game::MoveBlockLeft(){
    if(!gameOver){
        currentBlock.Move(0, -1); 
        if(isBlockOutside() || !BlockFits()){
            currentBlock.Move(0, 1);
        }
    }
}

void Game::MoveBlockRight(){
    if(!gameOver){
        currentBlock.Move(0, 1);
        if(isBlockOutside() || !BlockFits()){
            currentBlock.Move(0, -1);
        }
    }
}

void Game::MoveBlockDown(){
    if(!gameOver){
        currentBlock.Move(1, 0);
        if(isBlockOutside() || !BlockFits()){
            currentBlock.Move(-1, 0);
            LockBlockInPlace();
        }
    }
}


void Game::RotateBlock(){
    if(!gameOver){
        currentBlock.Rotate();
        if(isBlockOutside() || !BlockFits()){
            currentBlock.UndoRotate();
        }else{
            PlaySound(rotateSound);
        }
    }
}

void Game::LockBlockInPlace(){
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item : tiles){
        grid.grid[item.row][item.col] = currentBlock.id;
    }
    currentBlock = nextBlock;   
    if(!BlockFits()){
        gameOver = true;
    }
    nextBlock = GetRandomBlock();
    int rowsCleared=grid.ClearFullRows();
    if(rowsCleared > 0){
        PlaySound(clearSound);
        UpdateScore(rowsCleared, 0);
    }
}
    



bool Game::isBlockOutside(){
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position tile : tiles) {
        if (grid.isCellOutside(tile.row, tile.col)) {
            return true;
        }
    }
    return false;
}

bool Game::BlockFits(){
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position tile : tiles) {
        if (!grid.isCellEmpty(tile.row, tile.col)) {
            return false;
        }
    }
    return true;
}

void Game::Reset(){
    grid.Initialize();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    score = 0;
}

void Game::UpdateScore(int linesCleared, int moveDownPoints){
    switch(linesCleared){
        case 1:
            score += 100;
            break;
        case 2:
            score += 300;
            break;
        case 3:
            score += 500;
            break;
        default:
            break;
    }
    score += moveDownPoints;
}