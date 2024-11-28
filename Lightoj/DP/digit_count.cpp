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
const ll N = 11;
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

ll n,m;
v64 S(N);
ll dp[N][N];

ll f(ll num,ll digits){
    if(digits==n){
        return 1;
    }

    if(digits>n) return 0;

    if(dp[num][digits]!=-1) return dp[num][digits];

    ll ans = 0;
    for(int i = 0; i<m; i++){
        if(num==0 || (abs(num - S[i]) <=2)){
            ans+= f(S[i] ,digits+1);
        }
    }
    
    return dp[num][digits] = ans;

}


void solve(ll t){
    ll temp,ans=0,i,j,k,a,b,c,u,v;
    cin>>m>>n;
    memset(dp, -1, sizeof dp);
    forn(i,m){
        cin>>S[i];
    }
    ans = f(0,0);
    // forn(i,m) cout << S[i] << " ";
    cout << "Case " << t << ": ";
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
