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

// refer to the problem cses-1668(Building Teams)

//Finding odd length cycle using graph bicoloring aka trying to color the graph using only two 
//color such that no adjacent node have the same color.

v64 adj[N];
ll color[N];
ll flag = 1;
void dfs(ll u, ll c){
    if(color[u]){
        if(color[u]!=c){
            flag = 0;//Odd length cycle found.
            return;
        }
        return;
    }
    color[u] = c;
    for(ll v: adj[u]){
        dfs(v,3-c);// either color 1 or color 2.
    }
}

void solve(){
    ll n,m,temp,ans=0,i,j,k,a,b,c,u,v;
    cin>>n>>m;
    forn(i,m){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(i =1; i<=n; i++){
        if(!color[i]){
            dfs(i,1);
        }
    }
    if(!flag) cout << "IMPOSSIBLE";
    else for(i = 1; i<=n; i++) cout << color[i] << " ";
    cout << nn;
    
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
