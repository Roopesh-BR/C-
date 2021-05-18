#ifndef BoardFile
#define BoardFile

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

vector<vector<State>> Search(vector<vector<State>> grid, vector<int> init, vector<int> goal);
vector<vector<State>> ReadBoardFile(string path);
vector<State> ParseLine(string line);
bool compare(const vector<int> v1, const vector<int> v2);
string CellString(State cell);
#endif