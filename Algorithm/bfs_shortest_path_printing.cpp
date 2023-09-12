#include <bits/stdc++.h> 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef vector<ll> v64;
typedef vector<p64> vp64;
ll mod = 1e9+7;
const ll N = 1000005;
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

vector<ll> adj[N];
int vis[N];


void solve(){
    ll n,m,temp,ans=0,i,j,k,a,b,c;
    cin>>n>>m;
    ll prev[n+1];
    forn(i,m){
    	ll u,v; cin>>u>>v;
  		adj[u].pb(v);
  		adj[v].pb(u);
    }
    queue<ll> q;
    ll src = 1;
    q.push(src);
    vis[src] = 1;
    while(!q.empty()){
    	ll u = q.front();
    	q.pop();
    	for(auto v: adj[u]){
    		if(!vis[v]){
    			vis[v] = 1;
    			prev[v] = u;
    			q.push(v);
    		}
    	}
    }

    ll destination = n;
    v64 path;
    while(destination!=src){
    	path.pb(destination);
    	destination = prev[destination];
    }
    path.pb(src);
    reverse(all(path));
    cout << path.size() << nn;
    forn(i,path.size()){
    	cout << path[i] << " ";
    }
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
