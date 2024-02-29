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


//Count of pairs in an array whose product is a perfect square

ll prime[N+5],k[N+5];

void sieve(){
    for (ll i = 1; i < N; i++) k[i] = i;

    for (ll i = 2; i < N; i++) {
        if (prime[i] == 0){
            for (ll j = i; j < N; j += i) {
 
                prime[j] = 1;
 
                while (k[j] % (i * i) == 0)
                    k[j] /= (i * i);
            }
        }
    }
}

ll countPairs(v64 &arr){
    ll n = arr.size();
    map<ll,ll> freq;
    ll temp = n;
    ll sum = 0;
    // Store the frequency of k
    for (ll i = 0; i < n; i++){
        if(!arr[i]){
            sum+= (temp-1);
            temp--;
        }else freq[k[arr[i]]]++;

    }

 
    for (auto i : freq) {
        sum += ((i.second - 1) * i.second) / 2;
    }
    
    return sum;
}

void solve(ll t){
    ll n,m,temp,ans=0,i,j,k,a,b,c,u,v;
    cin>>n;
    v64 arr(n);
    forn(i,n) cin>>arr[i];
    cout << countPairs(arr) << nn;
    
}
int main()
{
    sieve();
    fast_cin();
    ll t = 1;
    // cin >> t;
    for(int it=1;it<=t;it++) {
        solve(it);
    }
    return 0;
}
