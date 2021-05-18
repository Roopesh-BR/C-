#include"Search.h"

vector<vector<State>> Search(vector<vector<State>> grid, vector<int> init, vector<int> goal){

    int x = init[0];
    int y = init[1];
    int g = 0;
    int h = Heuristic({x,y}, goal);
    vector<vector<State>> path;

    vector<vector<int>> open;
    vector<int> current;
    AddToOpen(x, y, g, h, open, grid);
    

    while(open.size() > 0){
        CellSort(&open);

        int n = open.size();
       current = open[n-1];
       open.pop_back();
       int x = current[0];
       int y = current[1];
       grid[x][y] = State::kPath;

       if(x == goal[0] && y == goal[1]){
           grid[init[0]][init[1]] = State::kStart;
           grid[goal[0]][goal[1]] = State::kFinish;
           return grid;
       }
       
           ExpandNeighbors(current, open, grid, goal);
       
    }
    cout<<"No path found!!"<<"\n";
    return grid;
}
