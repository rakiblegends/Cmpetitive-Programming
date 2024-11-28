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
const ll N = 105;
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

ll dp[N][N];
string s;

ll f(ll fidx,ll lidx){
    if(fidx>=lidx) return 0;
    if(dp[fidx][lidx]!=-1) return dp[fidx][lidx];

    ll ans = inf;
    if(s[fidx]==s[lidx]) ans = min(ans,f(fidx+1,lidx-1));
    else{
        ll x = 1+f(fidx+1,lidx);
        ll y = 1+f(fidx,lidx-1);
        ans = min(ans,min(x,y));
    }
    return dp[fidx][lidx] = ans;
}


void solve(ll t){
    ll n,m,temp,ans=0,i,j,k,a,b,c,u,v;
    memset(dp, -1, sizeof dp);
    cout << "Case " << t << ": ";
    cin>>s;
    cout << f(0,s.size()-1) << nn;
    
    
    
}
int main()
{
    fast_cin();
    ll t = 1;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve(it);
    }
    return 0;
}
