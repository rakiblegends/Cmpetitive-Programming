//Calculate Ncr while caring for the overflow.
ll ncrov(ll n, ll r){
    ll ans = 1;
    for(ll i = 0; i<r; i++){
        ans*=(n-i);
        ans/=(i+1);
    }
    return ans;
}
