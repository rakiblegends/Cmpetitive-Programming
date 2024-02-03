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
 

/////Problem CSES: 1676- Road Construction.



ll parent[N],sz[N];
priority_queue<ll> pq;
void make_set(ll n){
    for(ll i = 0; i<=n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}
 
ll find_set(ll u){
    if(parent[u]==u) return u;
    return parent[u] = find_set(parent[u]);
}
 
bool union_set(ll u, ll v){
    ll a = find_set(u);
    ll b = find_set(v);
 
    if(a!=b){
        if(sz[a]>sz[b]){
            swap(a,b);
        }
        parent[a] = b;
        sz[b]+= sz[a];
        pq.push(sz[b]);
        return true;
    }else return false;
}
 
 
 
void solve(){
    ll n,m,temp,ans=0,i,j,k,a,b,c,u,v;
    cin>>n>>m;
    ans = n;
    make_set(n);
    forn(i,m){
        cin>>u>>v;
        if(union_set(u,v)) ans--;
        cout<<ans << " " << pq.top() << nn;
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
