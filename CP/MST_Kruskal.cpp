#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u,v,w;
};
bool cmp(Edge a, Edge b){return a.w<b.w;}

int find(vector<int>& parent,int x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent,parent[x]);
}

int main(){
    int n,e; 
    cout<<"Enter nodes and edges: ";
    cin>>n>>e;
    vector<Edge> edges(e);
    cout<<"Enter edges u v w:\n";
    for(int i=0;i<e;i++) cin>>edges[i].u>>edges[i].v>>edges[i].w;
    sort(edges.begin(),edges.end(),cmp);

    vector<int> parent(n+1);
    for(int i=1;i<=n;i++) parent[i]=i;

    int mst=0;
    for(auto ed: edges){
        int pu=find(parent,ed.u), pv=find(parent,ed.v);
        if(pu!=pv){
            mst+=ed.w;
            parent[pu]=pv;
        }
    }
    cout<<"MST weight = "<<mst<<"\n";
}
