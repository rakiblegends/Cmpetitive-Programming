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
vector<pair<ll,ll>> adj[N];



void solve(){
    ll n,m,temp,ans=0,i,j,k,a,b,c;
    cin>>n>>m;
    forn(i,m){
    	ll u,v,w; cin>>u>>v>>w;
    	adj[u].pb({v,w});
    	adj[v].pb({u,w});
    }

    ll dis[n+1],prev[n+1];
    forn(i,n+1) dis[i] = inf;
   	ll src = 1;
   	dis[src] = 0;
   	priority_queue<pair<ll,ll>> pq;
   	pq.push({0,src});
   	while(!pq.empty()){
   		auto x = pq.top();
   		pq.pop();
   		ll u = x.se;
   		ll d = -x.fi;
   		if(dis[u]<d) continue;
   		for(auto y: adj[u]){
   			ll v = y.fi;
   			ll w = y.se;
	   		if(dis[v]>d+w){
	   			dis[v] = d+w;
	   			pq.push({-dis[v],v});
	   			prev[v] = u;//for printing the shortest path
	   		}
	   	}
   	}

   	if(dis[n]==inf) cout << "IMPOSSIBLE\n";
   	else{
   		ll destination = n;
   		v64 vv;
   		while(destination!=src){
   			vv.pb(destination);
   			destination = prev[destination];
   		}
   		vv.pb(src);
   		reverse(all(vv));
   		cout << vv.size() << nn;
   		forn(i,vv.size()) cout << vv[i] << " ";
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
