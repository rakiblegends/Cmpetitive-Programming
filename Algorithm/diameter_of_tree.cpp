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
const ll N = 200005;
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

//Finding tree diameter.

v64 adj[N];

v64 dis(N); //Stores depth of tree for each node from the root.

void dfs(ll u, ll p, ll d){
    dis[u] = d;
    for(ll v: adj[u]){
        if(v!=p){
            dfs(v,u,d+1);
        }
    }
}


void solve(){
    ll n,m,temp,ans=0,i,j,k,a,b,c,u,v;
    cin>>n;
    forn(i,n-1){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0,0);
    ll mx_dpth=0, mx_node= 0;
    for(i = 1; i<=n; i++){
        if(dis[i]>mx_dpth){
            mx_dpth = dis[i];
            mx_node = i;
        }
    }
    dfs(mx_node,0,0);
    cout << *max_element(all(dis)) << nn;

    
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
