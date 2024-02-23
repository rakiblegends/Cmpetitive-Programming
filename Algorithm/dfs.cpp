#include<bits/stdc++.h>
using namespace std;
const long long N = 1e5+10;

vector<ll> adj[N];
//vector<pair<ll,ll>> adj[N];
ll vis[N];
void dfs(ll u){
    vis[u] = 1;
    for(auto v: adj[u]){
        if(!vis[v]) dfs(v);
    }

}

int main(){
    long long n,m,u,v;
    cin>>n>>m;
    for(int i = 0; i<m; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);//Undirected
        //for weighted graph uncomment below code.
        //cin>>u>>v>>w;
        //adj[u].pb({v,w});
        //adj[v].pb({u,w});
    }
    dfs(0);
    // for(int i = 0; i<n; i++){
    //     cout << i << "-> ";
    //     for(int j = 0; j<g[i].size();j++){
    //         cout << g[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    return 0;
}
