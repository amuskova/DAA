#include <iostream>
#include <list>
using namespace std;

class Graph {
    int V;

    list<int>* adj;
    void DFSUtil(int v, bool visited[]);

public:
    Graph(int V);
    ~Graph();
    void addEdge(int v, int w);
    int connectedComponents();
};

int Graph::connectedComponents()
{
    int answer = -1;
    bool* visited = new bool[V];
    for (int v = 0; v < V; v++)
        visited[v] = false;

    for (int v = 0; v < V; v++) {
        if (visited[v] == false) {
            DFSUtil(v, visited);

            answer++;
        }
    }
    delete[] visited;
    return answer;
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    //cout << v << " ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

Graph::~Graph() { delete[] adj; }

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

int n,m;

void init(){
    scanf("%d %d", &n, &m);
    Graph g(n+1);
    int from,to;
    for(int i = 0; i < m ; i++){
        cin>>from>>to;
        g.addEdge(from,to);
    }

    cout<<g.connectedComponents();
}
int main()
{
    init();

    return 0;
}
