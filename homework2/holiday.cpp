#include <cstdio>
#include <queue>
#include <vector>
#include <limits.h>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#define pi pair<int,int>

using namespace std;

int n,m,k, mineq = -1,maxeq =0;
int used[100005], dist[100005];

struct Edge{
    int to,weight,eq;

    Edge(int to=0, int eq = 0, int weight = 0){
        this->to = to;
        this->weight = weight;
        this->eq = eq;
    }
};

vector<Edge>gr[100005];

void init(){
    int from,to,weight, eq;

    scanf("%d %d %d",&n,&m, &k);
    for(int i=0;i<m;i++){
        scanf("%d %d %d %d",&from,&to,&eq, &weight);
        Edge edge(to, eq,weight);
        gr[from].push_back(edge);
        if(eq > maxeq)
        {
            maxeq = eq;
        }
    }
}

bool dijkstra(int start, int e){

    priority_queue<pi,vector<pi>, greater<pi>> toVisit;
    fill(dist,dist+n+1,INT_MAX);
    fill(used, used+n+1,0);
    dist[start] = 0;
    toVisit.push({0,start});

    while(!toVisit.empty()){
        int node = toVisit.top().second;
        toVisit.pop();

        if(used[node] == 1)continue;

        used[node]=1;

        for(Edge neighbor:gr[node]){
            if(dist[node] + neighbor.weight <= dist[neighbor.to] && neighbor.eq <= e){
                dist[neighbor.to] = dist[node] + neighbor.weight;
                toVisit.push({dist[neighbor.to],neighbor.to});
            }
        }
    }
    if(dist[n] < k)
    {
        mineq = e;
        return true;
    }
    return false;
}
int bs(int l, int r)
{
    if(l<=r)
    {
        int mid = (r + l)/2;
        if(dijkstra(1,mid) == true)
        {
            return bs(l, mid-1);
        }else{
            return bs(mid+1, r);
        }

    }
    return mineq;
}
int main(){
    init();
    cout<<bs(1, maxeq);
    return 0;
}
