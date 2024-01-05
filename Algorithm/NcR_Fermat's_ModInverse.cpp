#include<bits/stdc++.h>
#define ll long long int
ll mod = 1e9+7;
using namespace std;

ll power(ll x,ll y){
	ll res = 1; // Initialize result
	x = x % mod; 
	while (y > 0){
		if (y & 1) res = (res * x) % mod;
		y = y >> 1;
		x = (x * x) % mod;
	}
	return res;
}
// Returns n^(-1) mod p
ll modInverse(ll n){
	return power(n, mod - 2);
}

// Returns nCr % p using Fermat's little theorem.
ll nCrModPFermat(ll n,ll r){
	if (n < r) return 0;
	if (r == 0) return 1;
	ll fac[n + 1];
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % mod;
	return (fac[n] * modInverse(fac[r]) % mod * modInverse(fac[n - r]) % mod) % mod;
}

int main(){
    cout << nCrModPFermat(5,2,13) << "\n";
    return 0;
}
