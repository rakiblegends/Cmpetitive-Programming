#include <bits/stdc++.h>
#define M 100000
using namespace std;
bitset <M> primes ;
void sieve(){
    primes[0]=true,primes[1]=true;
    for(int i=3;i*i<=M;i++){
        if(primes[i]==false){
            for(int j=i*i;j<=M;j+=i){
                primes[j]=true;
            }
        }
    }
}
int main(){
    sieve();
    vector<long long int> prime;
    vector <long long int> :: iterator it;
    prime.push_back(2);
    for(int i=3;i<=M;i+=2){
        if(primes[i]==false) prime.push_back(i);
    }
    for(it = prime.begin();it != prime.end();it++){
        cout << *it << " ";
    }
    return 0;
}
