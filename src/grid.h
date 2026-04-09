#pragma once
#include <vector>
#include <raylib.h>
class Grid{
    private:
     int rows;
     int cols;
     int cellSize;
     std::vector<Color> colors;

     bool IsRowFull(int row);
     void ClearRow(int row);
     void MoveRowDown(int row, int numRows);







    public:
    int grid[20][10];
    Grid();
    void Initialize();
    void Draw();
    bool isCellOutside(int row,int col);
    bool isCellEmpty(int row, int col);

    int ClearFullRows();
};