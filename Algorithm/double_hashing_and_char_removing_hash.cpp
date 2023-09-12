//CF-1800D, Remove Two letter solution.


#include <bits/stdc++.h> 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll Mod = 1e9+7;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define nn "\n"
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

ll bigmod(ll b,ll p)
{
    ll ans=1;
    while(p)
    {
        if(p&1)
            ans = (ans*b)%Mod;
        b = (b*b)%Mod;
        p = p/2;
    }
    return ans;
}

ll A[300000],B[300000];//Cumulaive forward double hashing

ll hashFunction(string key) {
    ll hashCode = 0;
    for (ll i = 0; i < key.length(); i++) {
        hashCode += (((key[i]-'a'+1)%Mod * bigmod(27,i))%Mod);
        hashCode%=Mod;
        A[i] = hashCode;
    }
    return hashCode;
}

ll hashFunction2(string key) {
    ll hashCode = 0;
    for (ll i = 0; i < key.length(); i++) {
        hashCode += (((key[i]-'a'+1)%Mod * bigmod(31,i))%Mod);
        hashCode%=Mod;
        B[i] = hashCode;
    }
    return hashCode;
}

ll modInverse(ll n, ll p)
{
    return bigmod(n, p - 2);
}

void solve(){
    ll n,m,temp,ans=0,ans1=0,i,j,hash,hash1,temp1;
    cin>>n;
    string s; cin>>s;
    set<ll> st,st1;

    hash = hashFunction(s);
    hash1 = hashFunction2(s);
    for(i = 1; i<n; i++){

        temp = hash;
        temp1 = hash1;

        temp = ((temp-A[i])+Mod)%Mod;
        temp1 = ((temp1-B[i])+Mod)%Mod;

        temp = (temp * modInverse(27,Mod))%Mod;
        temp = (temp * modInverse(27,Mod))%Mod;

        temp1 = (temp1 * modInverse(31,Mod))%Mod;
        temp1 = (temp1 * modInverse(31,Mod))%Mod;

        if(i>1){
            temp = (temp+A[i-2])%Mod;
            temp1 = (temp1+B[i-2])%Mod;
        }
        if((!st.count(temp)) || (!st1.count(temp1))){
            ans++;
            st.insert(temp);
            st1.insert(temp1);
        }
    }
    cout << ans << "\n";
}
int main()
{
    fast_cin();
    ll t = 1;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}