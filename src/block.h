#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block {
    private:
    int cellSize;
    int rotationState;
    std::vector<Color> colors;
    int rowOffset;
    int colOffset;

    public:
    Block();
    void Draw(int Offsetx,int Offsety);
    void Move(int rows, int cols);
    std::vector<Position> GetCellPositions();
    int id;
    std::map<int, std::vector<Position>> cells;
    void Rotate();
    void UndoRotate();
    
};
