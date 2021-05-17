#include"OptimalPath.h"

int main() {
  auto board = ReadBoardFile("C:/roopesh/new_project/Udacity/C++ nanodegree/foundations/Board.txt");
  PrintBoard(board);
  search(board,{0,0},{4,5},1);
}