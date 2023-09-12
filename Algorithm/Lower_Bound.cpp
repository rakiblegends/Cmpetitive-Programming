

ll BS(const vector<ll> &v, ll target){
    ll l = 0, r = v.size()-1,mid,ans;
    ans = -1;
    while(l<=r){
        mid = l+(r-l)/2;
        if(v[mid]>=target){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return ans;
}