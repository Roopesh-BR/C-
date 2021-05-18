
#ifndef A_star
#define A_star
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

vector<vector<State>> ReadBoardFile(string path);
vector<vector<State>> Search(vector<vector<State>> grid, vector<int> init, vector<int> goal);
bool compare(const vector<int> v1, const vector<int> v2);
void PrintBoard(const vector<vector<State>> board);
#endif


void CellSort(vector<vector<int>> *v)
{
    sort(v->begin(), v->end(), compare);
}


bool compare(const vector<int> v1, const vector<int> v2){
    if((v1[2] + v1[3]) > (v2[2] + v2[3])){

        return true;
    }
    else{
    return false;
    }
}



