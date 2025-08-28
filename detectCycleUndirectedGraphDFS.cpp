#include <bits/stdc++.h>
using namespace std;

vector<int> adjacencyList[105];
bool visitedArray[105];
int parentArray[105];
bool detectCycle;

void dfs(int sourceNode)
{
    visitedArray[sourceNode] = true;

    for (int childNode : adjacencyList[sourceNode])
    {
        if (visitedArray[childNode] == true && parentArray[sourceNode] != childNode)
        {
            detectCycle = true;
        }

        if (visitedArray[childNode] == false)
        {
            parentArray[childNode] = sourceNode;
            dfs(childNode);
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
        adjacencyList[secondNode].push_back(firstNode);
    }

    memset(visitedArray, false, sizeof(visitedArray));
    memset(parentArray, -1, sizeof(parentArray));
    detectCycle = false;

    for (int i = 0; i < numberOfNode; i++)
    {
        if (visitedArray[i] == false)
        {
            dfs(i);
        }
    }

    if (detectCycle == true)
    {
        cout << "Cycle Detected" << endl;
    }
    else
    {
        cout << "There is no Cycle" << endl;
    }

    return 0;
}

// Input
// 5 4
// 1 0
// 2 3
// 3 4
// 4 2