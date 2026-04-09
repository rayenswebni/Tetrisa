#include "grid.h"
#include <raylib.h>
#include <vector>
#include "colors.h"

Grid::Grid() {
    rows = 20;
    cols = 10;
    cellSize = 30;
    Initialize();
    colors = GetCellColors();
}




void Grid::Initialize(){
     for(int i= 0; i < rows; i++) {
        for(int j= 0; j < cols; j++) {
            grid[i][j] = 0;
        }
    }
}

void Grid::Draw(){
    for(int i= 0; i < rows; i++) {
        for(int j= 0; j < cols; j++) {
            // Draw cell based on value
            int cellValue = grid[i][j];
            DrawRectangle(j * cellSize + 11, i * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
    
}

bool Grid::isCellOutside(int row, int col) {
    return row < 0 || row >= rows || col < 0 || col >= cols;
}

bool Grid::isCellEmpty(int row, int col) {
    return grid[row][col] == 0;
}

bool Grid::IsRowFull(int row) {
    for(int col = 0; col < cols; col++) {
        if(grid[row][col] == 0) {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row) {
    for(int col = 0; col < cols; col++) {
        grid[row][col] = 0;
    }
}

void Grid::MoveRowDown(int row, int numRows){
    for(int col = 0; col < cols; col++) {
        grid[row + numRows][col] = grid[row][col];
        grid[row][col] = 0;
    }
}

int Grid::ClearFullRows(){
    int completed = 0;
    for(int row = rows -1 ; row >= 0; row--) {
        if(IsRowFull(row)) {
            ClearRow(row);
            completed++;
        }
        else if(completed > 0) {
            MoveRowDown(row, completed);
        }
    }
    return completed; //score calculation will be done in main.cpp
}