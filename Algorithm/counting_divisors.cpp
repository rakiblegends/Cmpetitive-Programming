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
#define m 1000010

ll primes[m], cnt, siv[m];

void sieve(){
    long long int i, j;
    for (i=3; i<m; i+=2)
        if(!siv[i])
            for (j=i*i; j<m; j+=i+i)
                siv[j]=1;
    primes[cnt++]=2;
    for (i=3; i<m; i+=2)
        if(!siv[i]) primes[cnt++]=i;
    return;
}

void solve(ll t){
    ll n,sum=1,s,k,i;
    cin>>n;
    cout << "Case " << t << ": ";


    // finding the number of divisors of N
    for(i=0;i<m && primes[i]*primes[i]<=n;i++){
        if(n%primes[i]==0){
            k=0;
            while(n%primes[i]==0){
                n/=primes[i];
                k++;
                if(n==0 || n==1)
                    break;
            }
            sum*=k+1;
        }
    }

        /* If the number N is divided by a prime number than the
        sum has to be multiped by (1+1) where first 1 is the count of
        that prime number, N is divisible by and second 1 is the plus one
        of the formula. */

        if(n!=1) sum*=2;
        cout << sum-1 <<nn;
    
}
int main()
{
    sieve();
    fast_cin();
    ll t = 1;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve(it);
    }
    return 0;
}
