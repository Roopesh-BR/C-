#include"Heuristic.h"

int Heuristic(const vector<int> start,const vector<int> goal){
    int distance = abs(goal[0] - start[0]) + abs(goal[1] - start[1]);

    return distance;
}