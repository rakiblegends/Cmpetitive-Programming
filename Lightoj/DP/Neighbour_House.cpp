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


map<pair<ll,ll>,ll> dp;
vector<ll> houses[22];
ll n;

ll f(ll indx, ll cur){
    if(indx==n) return 0;
    if(dp[{cur,indx}]) {
        // cout << colors << nn;
        return dp[{cur,indx}];
    }

    ll x = inf;

    for(int i = 0; i<3; i++){
        if(cur==i) continue;
        else{
            x = min(x,houses[indx][i]+f(indx+1,i));
        }
    }
    return dp[{cur,indx}] = x;

}


void solve(ll t){
    ll m,temp,ans=0,i,j,k,a,b,c,u,v;
    cout << "Case " << t << ": ";
    cin>>n;
    dp.clear();
    forn(i,n){
        houses[i].clear();
        forn(j,3){
            cin>>temp;
            houses[i].pb(temp);
        } 
    }
    ans = f(0,-1);
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
