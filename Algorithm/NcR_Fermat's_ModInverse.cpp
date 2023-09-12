#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll power(ll x,ll y,ll p){
	ll res = 1; // Initialize result
	x = x % p; 
	while (y > 0){
		if (y & 1) res = (res * x) % p;
		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}
// Returns n^(-1) mod p
ll modInverse(ll n,ll p){
	return power(n, p - 2, p);
}

// Returns nCr % p using Fermat's little theorem.
ll nCrModPFermat(ll n,ll r,ll p){
	if (n < r) return 0;
	if (r == 0) return 1;
	ll fac[n + 1];
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
	return (fac[n] * modInverse(fac[r], p) % p
			* modInverse(fac[n - r], p) % p)
		% p;
}

int main(){
    cout << nCrModPFermat(5,2,13) << "\n";
    return 0;
}
