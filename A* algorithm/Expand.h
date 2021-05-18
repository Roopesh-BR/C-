#ifndef Expand
#define Expand

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include<cstdlib>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

enum class State {kEmpty, kObstacle, kClosed, kPath, kStart, kFinish};

int Heuristic(vector<int> start, vector<int> goal);
void AddToOpen( int x, int y, int g, int h, vector<vector<int>> &open, vector<vector<State>> &closed);
bool CheckValidCell(const int x, const int y, const vector<vector<State>> grid);


#endif