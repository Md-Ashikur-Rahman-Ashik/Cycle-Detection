#include <bits/stdc++.h>
using namespace std;

vector<int> adjacencyList[105];
bool visitedArray[105];
bool pathVisited[105];
bool detectCycle;

void dfs(int sourceNode)
{
    visitedArray[sourceNode] = true;
    pathVisited[sourceNode] = true;

    for (int childNode : adjacencyList[sourceNode])
    {
        if(visitedArray[childNode] == true && pathVisited[childNode] == true){
            detectCycle = true;
        }

        if (visitedArray[childNode] == false)
        {
            dfs(childNode);
            pathVisited[childNode] = false;
        }
    }
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
        if (visitedArray[i] == false)
        {
            dfs(i);
        }
    }

    if(detectCycle){
        cout << "Cycle Detected" << endl;
    } else{
        cout << "Cycle not detected" << endl;
    }

    return 0;
}

// Input
// 4 4
// 0 1
// 1 2
// 2 3
// 3 0