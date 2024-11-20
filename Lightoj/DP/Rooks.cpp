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


ll dp[35][35];
ll fact[21];
ll ncr(ll n,ll r){
    if(n==r || r==0)return 1;
    else if(r==1)return n;
    else if(dp[n][r]!=(-1))return dp[n][r];
    dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);
    return dp[n][r];

}


void solve(ll t){
    ll n,m,temp,ans=0,i,j,k,a,b,c,u,v;
    cout << "Case " << t << ": ";
    cin>>n>>k;
    if(k>n){
        cout << 0 <<nn;
        return ;
    }
    ll res = ncr(n,k);
    cout << res*res*fact[k] << nn;
    
    
}
int main()
{
    fast_cin();
    ll t = 1;
    cin >> t;
    fact[0] = 1;
    for(ll i = 0; i<35; i++){
        for(ll j =0; j<35; j++){
            dp[i][j] = -1;
        }
    }
    for(ll i = 1; i<=20; i++) fact[i] = fact[i-1]*i;
    for(int it=1;it<=t;it++) {
        solve(it);
    }
    return 0;
}
