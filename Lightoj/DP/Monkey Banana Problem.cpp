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
const ll N = 300;
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

v64 vv[N];
ll dp[N][N];

ll f(ll n,ll i,ll j){

    if(i==n) {
        return 0;
    }

    if(j<0 || j>=n) return -inf;

    //Now dp

    if(dp[i][j]!=-1) return dp[i][j];
    
    ll x = vv[i][j]+ f(n,i+1,j+1);
    ll y = vv[i][j]+f(n,i+1,j-1);
    return dp[i][j] = max(x,y);
}



void solve(ll t){
    ll n,m,ans=0,temp,i,j,k,a,b,c,u,v;
    cin>>n;


    cout << "Case " << t<< ": ";
    n = n+(n-1);
    forn(i,n) vv[i].clear();

    for(i = 0; i<N; i++){
        for(j = 0; j<N; j++){
            dp[i][j] = -1;
        }
    }

    j = (n/2); 
    for(i = 1; i<=n; i++){
        for(k = 0; k<j; k++){
            vv[i-1].pb(0);
        }
        if(i<((n+1)/2)) j--;
        else j++;
        if(i<=((n+1)/2)) temp = i;
        else{
            temp = abs(i-(2*((n+1)/2)));
        }
        forn(k,temp){
            cin>>m;
            vv[i-1].pb(m);
            if(vv[i-1].size()!=n) vv[i-1].pb(0);
        }
        while(vv[i-1].size()<n) vv[i-1].pb(0);
    }

    ans = f(n,0,n/2);
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
