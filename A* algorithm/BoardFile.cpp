#include"BoardFile.h"

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

//Print the Board
void PrintBoard(const vector<vector<State>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << CellString(board[i][j]);
    }
    cout << "\n";
  }
}

string CellString(State cell) {
   switch(cell) {
    case State::kObstacle: return "⛰️   ";
    case State::kPath: return "🚗   ";
    case State::kStart: return "🚦   ";
    case State::kFinish: return "🏁 ";
    default: return "0   "; 
  }
}