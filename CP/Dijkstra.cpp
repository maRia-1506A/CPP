#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cout<<"Enter nodes and edges: ";
    cin>>n>>e;
    vector<vector<pair<int,int>>> adj(n+1);
    cout<<"Enter edges u v w:\n";
    for(int i=0;i<e;i++){
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int src; cout<<"Enter source: "; cin>>src;

    vector<int> dist(n+1,1e9);
    dist[src]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,src});

    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        if(d!=dist[u]) continue;
        for(auto [v,w]: adj[u]){
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }

    cout<<"Shortest distances:\n";
    for(int i=1;i<=n;i++) cout<<"Node "<<i<<" = "<<dist[i]<<"\n";
}
