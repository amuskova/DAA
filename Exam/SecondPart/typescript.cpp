#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;
int N,M;
int counter = 0;

void printSolution(int cost[N][N], int path[N][N])
{
    for (int v = 0; v < N; v++)
    {
        for (int u = 0; u < N; u++)
        {
            if (u != v && path[v][u] != -1)
            {
                counter++;
            }
        }
    }
}

void floydWarshall(int adjMatrix[][N])
{
    int cost[N][N], path[N][N];
    for (int v = 0; v < N; v++)
    {
        for (int u = 0; u < N; u++)
        {
            cost[v][u] = adjMatrix[v][u];

            if (v == u)
                path[v][u] = 0;
            else if (cost[v][u] != INT_MAX)
                path[v][u] = v;
            else
                path[v][u] = -1;
        }
    }

    for (int k = 0; k < N; k++)
    {
        for (int v = 0; v < N; v++)
        {
            for (int u = 0; u < N; u++)
            {
                if (cost[v][k] != INT_MAX && cost[k][u] != INT_MAX
                    && cost[v][k] + cost[k][u] < cost[v][u])
                {
                    cost[v][u] = cost[v][k] + cost[k][u];
                    path[v][u] = path[k][u];
                }
            }

            if (cost[v][v] < 0)
            {
                cout << "Negative Weight Cycle Found!!";
                return;
            }
        }
    }
    printSolution(cost, path);
}

int main()
{
    cin>>N>>M;
    int adjMatrix[N][N];
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N ; j++){
            adjMatrix[i][j] = 0;
        }
    }
    int from, to, weight;
    for(int i = 0 ; i < M ; i++){
        cin>>from>>to>>weight;
        adjMatrix[from][to] = weight;
    }
    floydWarshall(adjMatrix);

    return 0;
}
