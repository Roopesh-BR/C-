#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

enum class State {kEmpty, kObstacle};


//Parse the string into a vector
vector<State> ParseLine(string line) {
    istringstream sline(line);
    int n;
    char c;
    vector<State> row;

    while (sline >> n >> c && c == ',') {
      //  State::kEmpty if n is 0
      //  State::kObstacle otherwise.
      switch (n) {
          case 0 : row.push_back(State::kEmpty);
          break;
          case 1 : row.push_back(State::kObstacle);
          break;
      }
    }
    return row;
}

//read the iputs to Board from board.txt file
vector<vector<State>> ReadBoardFile(string path) {
  ifstream myfile (path);
  vector<vector<State>> board{};
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      vector<State> row = ParseLine(line);
      board.push_back(row);
    }
  }
  return board;
}


string CellString(State cell) {
  switch(cell) {
    case State::kObstacle: return "⛰️   ";
    default: return "0   "; 
    }
}

//Print the Board
void PrintBoard(const vector<vector<State>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << CellString(board[i][j]);
    }
    cout << "\n";
  }
}


//Serach the optimal path steps to the goal

void search (vector<vector<State>> board, vector<int> init, vector<int> goal, int cost){

  vector<vector<int>> closed = {{0,0,0,0,0,0},
                                {0,0,0,0,0,0},
                                {0,0,0,0,0,0},
                                {0,0,0,0,0,0},
                                {0,0,0,0,0,0}};

 vector<vector<int>> delta = {{-1,0},     //up
                              {0,-1},     //left
                              {1,0},       //down
                              {0,1}};      //right                         


 closed[0][0] = 1;
 int x = init[0];
 int y = init[1];
 int g = 0;
 int path = 0;
 vector<vector<int>> open = {{g,init[0],init[1]}};
 vector<int> next = {};

 bool found = false;
 bool resign = false;

 while( found == false && resign == false){

    if(open.size() == 0){
      resign = true;
      cout<<"Fail";

  }
  else{

    sort(open.begin(), open.end());
    reverse(open.begin(), open.end());
    int n = open.size();
    next = open[n-1];
    open.pop_back();

    x = next[1];
    y = next[2];
    g = next[0];


      if(x == goal[0] && y == goal[1]){

        found = true;
        path = g;
        cout<<"\nThe optimal steps to the goal is : "<<path<<std::endl;
      }
      else{
        for(int i = 0; i< delta.size(); i++){

        int  x2 = x + delta[i][0];
        int  y2 = y + delta[i][1];
        

        if( x2 >= 0 && x2 < board.size() && y2 >= 0 &&  y2 < board[0].size()){
          if(closed[x2][y2] == 0 && board[x2][y2] == State::kEmpty){

            int g2 = g + cost;
            open.push_back({g2,x2,y2});
            closed[x2][y2] = 1;
          }
        }
        }
      }
  }
 }
}
