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

    vector<int> vis(n+1,0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,1});
    int mst=0;

    while(!pq.empty()){
        auto [w,u]=pq.top(); pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        mst+=w;
        for(auto [v,wt]: adj[u]) if(!vis[v]) pq.push({wt,v});
    }
    cout<<"MST weight = "<<mst<<"\n";
}
