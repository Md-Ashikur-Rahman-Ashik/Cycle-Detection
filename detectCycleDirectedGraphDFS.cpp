#include <bits/stdc++.h>
using namespace std;

vector<int> adjacencyList[105];
bool visitedArray[105];
bool pathVisited[105];
bool detectCycle;

void dfs(int sourceNode){
    visitedArray[sourceNode] = true;
}

int main()
{
    int numberOfNode, numberOfEdge;
    cin >> numberOfNode >> numberOfEdge;

    for (int i = 0; i < numberOfEdge; i++)
    {
        int firstNode, secondNode;
        cin >> firstNode >> secondNode;

        adjacencyList[firstNode].push_back(secondNode);
    }

    memset(visitedArray, false, sizeof(visitedArray));
    memset(pathVisited, false, sizeof(pathVisited));

    for (int i = 0; i < numberOfNode; i++)
    {
        if(visitedArray[i] == false){
            dfs(i);
        }
    }
    
    

    return 0;
}