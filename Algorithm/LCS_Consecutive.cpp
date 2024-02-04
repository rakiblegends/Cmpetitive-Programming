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

//Longest Increasing Consecutive Subssequence...... 
//Problem CF-605A, Sorting Railway Cars.



ll dp[N];//Holds the lics of elements ends with i.
ll lics(v64 &v){
    ll n = v.size();
    for(ll i = 0; i<n; i++){
        dp[v[i]] = dp[v[i]-1]+1;//LICS of v[i] is LICS of v[i-1] + 1.
    }
    ll ans = -inf;///Now ans has the Longest Incresing Cnsecutinve Subsequence.
    for(ll i = 1; i<=n; i++) ans = max(ans,dp[i]);
    return ans;
}



void solve(){
    ll n,m,temp,ans=0,i,j,k,a,b,c,u;
    cin>>n;
    v64 v(n); forn(i,n) cin>>v[i];
    ans = lics(v);
    cout << n-ans << nn;
    
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
