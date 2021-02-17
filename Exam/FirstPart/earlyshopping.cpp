#include <bits/stdc++.h>

using namespace std;

long n, m;
vector<bool> see;
set<long> input;

class Graph
{
private:
    map<long,map<long,long>> matrix;
    void DFS(long v,vector<bool> &visited,long &visit)
    {
        visited[v]=true;
        visit++;
        for(auto p : matrix[v])
        {
            if(!visited[p.first])
            {
                DFS(p.first,visited,visit);
            }
        }
    }
public:
    void connect(long v, long w)
    {
        matrix[v][w]=1;
        matrix[w][v]=1;
    }
    long countCol()
    {
        vector<bool> visited;
        visited.resize(n+1,false);
        long counter=0;
        long visit=0;
        set<long>::iterator i;
        for(i = input.begin() ; i != input.end() ; i++)
        {
            if(visited[*i]==false)
            {
                DFS(*i,visited,visit);
                counter++;
            }
        }
        counter = counter+n-visit;
        return counter;
    }
};

void init(){
    scanf("%ld %ld", &n, &m);
    see.resize(n+1, false);
    long a,b;
    Graph g;
    for(int i = 0; i < m; i++){
        scanf("%ld %ld", &a, &b);
        g.connect(a,b);
        input.insert(a);
        input.insert(b);
    }
    printf("%ld", g.countCol());
}
int main() {
    init();

    return 0;
}
