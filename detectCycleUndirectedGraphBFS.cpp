#include <bits/stdc++.h>
using namespace std;

vector<int> adjacencyList[105];
bool visitedArray[105];
int parentArray[105];
bool detectCycle;

void bfs(int sourceNode)
{
    queue<int> integerQueue;
    integerQueue.push(sourceNode);
    visitedArray[sourceNode] = true;

    while (!integerQueue.empty())
    {
        int parentNode = integerQueue.front();
        integerQueue.pop();

        for (int childNode : adjacencyList[parentNode])
        {
            if (visitedArray[childNode] == true && parentArray[parentNode] != childNode)
            {
                detectCycle = true;
            }

            if (visitedArray[childNode] == false)
            {
                integerQueue.push(childNode);
                visitedArray[childNode] = true;
                parentArray[childNode] = parentNode;
            }
        }
    }
}

int main()
{
    // Input
    // 6 5
    // 0 1
    // 1 2
    // 2 3
    // 3 0
    // 4 5

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
            bfs(i);
        }
    }

    if (detectCycle == true)
    {
        cout << "Cycle Detected" << endl;
    }
    else
    {
        cout << "No Cycle" << endl;
    }

    return 0;
}