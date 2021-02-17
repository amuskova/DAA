#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<int> answer;
int n,m,q;
class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isReachable(int s, int d);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool Graph::isReachable(int s, int d)
{
    if (s == d)
      return true;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    list<int>::iterator i;

    while (!queue.empty())
    {
        s = queue.front();
        queue.pop_front();
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (*i == d)
                return true;
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    return false;
}
void init(){
    scanf("%d %d", &n, &m);
    Graph g(n+1);
    int from, to;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &from, &to);
        g.addEdge(from, to);
    }
    scanf("%d", &q);
    answer.reserve(q);
    for(int i = 0; i < q; i++){
        scanf("%d %d", &from, &to);
        if(g.isReachable(from, to)){
            answer.push_back(1);
        }else{
            answer.push_back(0);
        }
    }
    for(int i = 0; i < q ; i++){
        cout<<answer[i];
    }

}
int main(){
    init();
    return 0;
}
