#include"Expand.h"

void ExpandNeighbors(vector<int> &current, vector<vector<int>> &open, vector<vector<State>> &grid, vector<int> goal){
       
        vector<vector<int>> delta = {{-1,0}, //up
                              {0,-1},        //left
                              {1,0},         //down
                              {0,1}};        //right  

        int x = current[0];
        int y = current[1];
        int g = current[2];
       for(int i = 0; i < delta.size(); i++){

           int x2 = x + delta[i][0];
           int y2 = y + delta[i][1];
            if( CheckValidCell(x2, y2, grid)){
                int g2 = g + 1;

               int h2 = Heuristic({x2,y2}, goal);
                AddToOpen(x2, y2, g2, h2, open, grid);

            }

       }

}
