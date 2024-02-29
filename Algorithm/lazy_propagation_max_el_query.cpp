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

// Lazy Propagation querying for maximum.


ll sum(ll a, ll b){
    return a+b;
}

ll n, sg[4*N],lazy[4*N];

void build(v64 &a, ll v, ll tl, ll tr){
    if (tl == tr) {
        sg[v] = a[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        sg[v] = max(sg[v*2], sg[v*2 + 1]);
    }
}

void push(ll v) {
    sg[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    sg[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll addend){
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        sg[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        ll tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        sg[v] = max(sg[v*2], sg[v*2+1]);
    }
}

ll query(ll v, ll tl, ll tr, ll l, ll r){
    if (l > r)
        return -inf;
    if (l == tl && tr == r)
        return sg[v];
    push(v);
    ll tm = (tl + tr) / 2;
    return max(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
}


void solve(ll t){
    ll m,temp,ans=0,i,j,k,b,c,u,v;

    cin>>n>>k;
    v64 arr(n+1);

    forn(i,n){
        cin>>arr[i+1];
    }
    build(arr,1,1,n);
    while(k--){
        ll op, idx, new_val,l,r;
        cin>>op;
        if(op==1){
            cin>>l>>r>>new_val;
            update(1,1,n,l,r,new_val);
        }else{
            cin>>l>>r;
            cout << query(1,1,n,l,r) << nn;
        }
    }
}
int main()
{
    fast_cin();
    ll t = 1;
    // cin >> t;
    for(int it=1;it<=t;it++) {
        solve(it);
    }
    return 0;
}
