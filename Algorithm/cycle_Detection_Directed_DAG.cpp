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
const ll N = 500005;
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

//Problem Refenrence CF 1931-F
//Verifying if a topological sort is possible or not.
//vis=0(Not visited)   vis=1(Exploring)   vis=2(Finished)

vector<ll> adj[N],vis(N);
ll nd = -1;
stack<ll> st;
void dfs(ll u){
    if(vis[u]==1){
        nd = u;
        return;
    }
    st.push(u);
    vis[u] = 1;
    for(auto v : adj[u]) {
        if(vis[v]!=2) dfs(v);
        if(nd!=-1) return;
    }
    vis[u] = 2;
    st.pop();
}

void solve(){
    ll n,m,temp,ans=0,i,j,k,a,b,c,u,v;
    cin>>n>>m;
    nd = -1;
    for(ll i = 1; i<=n; i++){
        adj[i].clear();
        vis[i]=0;
    }
    forn(i,m){
        v64 vv(n);
        forn(j,n) cin>>vv[j];
        for(j = 1; j<n-1; j++) adj[vv[j]].pb(vv[j+1]);
    }
    for(i = 1; i<=n; i++){
        if(!vis[i]) dfs(i);
    }
    if(nd==-1) yes;
    else no;
    
}
int main()
{
    fast_cin();
    ll t = 1;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}
