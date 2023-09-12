#include <bits/stdc++.h> 
using namespace std;
#define setbit(x,k) (x|= (1LL<<k))
#define checkbit(x,k) ((x>>k)&1)
#define clearbit(x,k) (x&= ~(1LL<<k))
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
 

void solve(){
    int n,i,j;
    cin>>n;
    for(i = 0; i<(1<<n); i++){
        for(j = 0; j<n; j++){
            if(checkbit(i,j)) cout << 1;
            else cout << 0;
        }
        cout << nn;
    }
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
