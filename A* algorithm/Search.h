#ifndef Search_use
#define Search_use
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

int Heuristic(const vector<int> start,const vector<int> goal);
void AddToOpen( int x, int y, int g, int h, vector<vector<int>> &open, vector<vector<State>> &closed);
void CellSort(vector<vector<int>> *v);
void ExpandNeighbors(vector<int> &current, vector<vector<int>> &open, vector<vector<State>> &grid, vector<int> goal);


#endif