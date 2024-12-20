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
const ll N = 17; 
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

ll vv[N][N];
ll n;
ll x=0;

ll dp[N][1ll<<N];
ll mask = 0;
ll f(ll i, ll mask){
    if(i==n){
        return 0;
    }
    if(dp[i][mask]!=-1) return dp[i][mask];
    ll sum = -1;
    for(int j = 0; j<n; j++){
        if(!checkbit(mask,j)){
            setbit(mask,j);
            sum = max(sum,vv[i][j]+f(i+1,mask));
            clearbit(mask,j);
        }
    }
    return dp[i][mask] = sum;
}


void solve(ll t){
    ll m,temp,ans=0,i,j,k,a,b,c,u,v;
    cout << "Case " << t << ": ";
    cin>>n;
    forn(i,n+1){
        forn(j,1ll<<(n+1)) dp[i][j] = -1;
    }
    forn(i,n){
        forn(j,n){
            cin>>vv[i][j];
        }
    }

    ans = f(0,0);
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
