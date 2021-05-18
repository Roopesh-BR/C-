#include"A_Star.h"

int main() {

  vector<int> init{0, 0};
  vector<int> goal{4, 5};  
  auto board = ReadBoardFile("C:/roopesh/new_project/Udacity/C++ nanodegree/foundations/Board.txt");
  auto solution = Search(board,init,goal);
  PrintBoard(solution);
  
}