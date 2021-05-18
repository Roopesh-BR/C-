#include"Checkcell.h"

bool CheckValidCell(const int x, const int y, const vector<vector<State>> grid){
    if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()){
        if(grid[x][y] == State::kEmpty){
            return true;
        }
        else{
            return false;
        }
    }
    return false;

}