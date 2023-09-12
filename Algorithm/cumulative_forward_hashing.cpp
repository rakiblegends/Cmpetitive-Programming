#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Mod = 1e9+7;

ll A[300000],B[300000];//Cumulaive forward double hashing


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

ll hashFunction(string key) {
    ll hashCode = 0;
    for (ll i = 0; i < key.length(); i++) {
        hashCode += (((key[i]-'a'+1)%Mod * bigmod(29,i))%Mod);
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

int main(){
    string s; 
    cin>>s;
    ll hash = hashFunction(s);
    ll hash2 = hashFunction2(s);

    cout << hash << " " << hash2 << "\n";

    return 0;
}