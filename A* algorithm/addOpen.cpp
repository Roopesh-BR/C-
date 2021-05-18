#include "addOpen.h"

void AddToOpen( const int x, const int y, const int g, const int h, vector<vector<int>> &open, vector<vector<State>> &closed){
        open.push_back({x, y, g, h});
        closed[x][y] = State::kClosed;     
}