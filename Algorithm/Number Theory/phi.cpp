#include <bits/stdc++.h> 
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

typedef unsigned long long int ll;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef vector<ll> v64;
typedef vector<p64> vp64;
ll mod = 1e9+7;
// double eps = 1e-12;
// ll dr[] = {1,-1,0,0};
// ll dc[] = {0,0,1,-1};
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
const ll N = 5000002;
ll phi[N+5];

void totient(){
    for(int i = 2; i<=N; i++){
        phi[i] = i;
    }
    for(ll h=2; h<=N; h++){
        if(phi[h]==h){
            for(ll x=h;x<=N; x+=h){
                phi[x]-= (phi[x]/h);
            }
        }
    }
    // Calculating cumuliative phi
    for(int i = 2; i<=N; i++){
        phi[i] = ((phi[i]*phi[i])+phi[i-1]);
    }
}

void solve(ll t){
    ll n,m,temp,ans=0,i,j,k,a,b,c,u,v;
    cout << "Case " << t << ": ";
    cin>>a>>b;
    ans = ((phi[b]-phi[a-1]));
    cout << ans << nn;
}

int main()
{
    fast_cin();
    totient();
    ll t = 1;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve(it);
    }
    return 0;
}
