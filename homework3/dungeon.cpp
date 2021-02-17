#include<bits/stdc++.h>
using namespace std;

typedef  pair<int, int> iPair;

struct Graph
{
    int V, E;
    vector< pair<int, iPair> > edges;

    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int w)
    {
        edges.push_back({w, {u, v}});
    }

    void kruskalMST();
};

struct DisjointSets
{
    vector<int> parent;
    vector<int> rnk;
    int n;

    DisjointSets(int n)
    {
        this->n = n;
        parent.reserve(n+1);
        rnk.resize(n+1,0);
        //iota(parent.begin(), parent.end(),0);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void merge(int x, int y)
    {
        x = find(x), y = find(y);

        if (rnk[x] > rnk[y])
            parent[y] = x;
        else
            parent[x] = y;

        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};


void Graph::kruskalMST()
{
    sort(edges.begin(), edges.end());

    DisjointSets ds(V);

    vector< pair<int, iPair> >::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        if(set_u == set_v)
        {
            printf("%d", it->first);
            return;
        }
        if (set_u != set_v)
        {
            ds.merge(set_u, set_v);
        }
    }
}

int main()
{

    int V, E;
    scanf("%d %d", &V, &E);
    Graph g(V, E);
    int f,t,w;
    for(int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &f,&t, &w);
        g.addEdge(f,t,w);
    }

    g.kruskalMST();

    return 0;
}
