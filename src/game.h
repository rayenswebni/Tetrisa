#pragma once
#include "grid.h"
#include "blocks.cpp"
#include <vector>


class Game{
    private:
    bool isBlockOutside();
    void LockBlockInPlace();
    bool BlockFits();
    void UpdateScore(int linesCleared,int moveDownPionts);
    void RotateBlock();
    void MoveBlockLeft();
    void MoveBlockRight();

    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    Grid grid;
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;

    Sound rotateSound;
    Sound clearSound;


    public:
    Game();
    ~Game();
    void HandleInput();
    void Draw(Font font);   
    void MoveBlockDown();
    void Reset();


    bool gameOver;
    int score;
    Music music;

};