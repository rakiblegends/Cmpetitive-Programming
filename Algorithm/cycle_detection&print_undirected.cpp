#include <bits/stdc++.h> 
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef vector<ll> v64;
typedef vector<p64> vp64;
ll mod = 1e9+7;
const ll N = 100005;
double eps = 1e-12;
ll dr[] = {1,-1,0,0};
ll dc[] = {0,0,1,-1};
#define forn(i,e) for(ll i = 0; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define pb push_back
#define fi first
#define se second
#define nn "\n"
#define inf 2e18
#define setbit(x,k) (x|= (1LL<<k))
#define checkbit(x,k) ((x>>k)&1)
#define clearbit(x,k) (x&= ~(1LL<<k))
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>


//Cycle detection and printing the cycle path in undirected graph.


v64 adj[N];
v64 vis(N);
ll nd=-1;//Node which completes the cycle.
stack<ll> st;//Stack for storing the visited nodes.
void dfs(ll u, ll prev){
    if(vis[u]){
        nd = u;//If a node is already visited and it is not the prev visited node then cycle formed.
        return;
    }
    st.push(u);
    vis[u] = 1;
    for(auto v: adj[u]){
        if(v!=prev){
            dfs(v,u);
            if(nd!=-1) return;//Return here because we don't want to pop stack data if a cycle has already been found
           
        }
    }
    st.pop();//Pop the stack when backtracking.
}


void solve(){
    ll n,m,temp,ans=0,i,j,k,a,b,c,u,v;
    cin>>n>>m;
    forn(i,m){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(i = 1; i<=n; i++){
        if(!vis[i] && nd==-1) dfs(i,0);
    }
    if(nd==-1) cout << "IMPOSSIBLE" << nn;
    else{
        v64 v;
        v.pb(nd);
        while(st.top()!=nd){
            v.pb(st.top());
            st.pop();
        }
        v.pb(nd);
        cout << v.size() << nn;
        forn(i,v.size()) cout << v[i] << " ";
        cout << nn;
    } 

}
int main()
{
    fast_cin();
    ll t = 1;
    // cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}
