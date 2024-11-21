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
ll mod = 100000007;
const ll N = 55;
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

v64 coin,available;
ll n,k;
ll dp[N][1005];

ll f(ll cur, ll indx){
    if(indx==n){
        if(cur==0) return 1;
        else return 0;
    }
    if(cur<0) return 0;
    if(dp[indx][cur]!=-1){
        return dp[indx][cur];
    }
    ll ans = 0;

    for(int ix = 0; ix<=available[indx]; ix++){
        ans = (ans+f(cur-(ix*coin[indx]),indx+1))%mod;
    }
    return dp[indx][cur] = ans;
    
    
}


void solve(ll t){
    ll m,temp,ans=0,i,j,a,b,c,u,v;
    cout << "Case " << t << ": ";

    cin>>n>>k;

    coin.clear();
    available.clear();

    forn(i,N){
        forn(j,1005){
            dp[i][j] = -1;
        }
    }
    forn(i,n){
        cin>>a;
        coin.pb(a);
    }
    forn(i,n){
        cin>>b;
        available.pb(b);
    }

    ans = f(k,0);
    cout << ans << nn;
    
    
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
