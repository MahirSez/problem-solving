#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e7 + 7;
int mark[MAX];
vector<ll>prm;

void seive() {

    
    for(ll i =2 ; i *i <MAX ; i ++) {
        
        if(mark[i]) continue;

        for(ll j = i*i ; j<MAX ; j+=i ) mark[j] = 1;
    }
    
    for(int i = 2 ; i < MAX ; i++ ) {
        
        if(mark[i] == 0 ) prm.push_back(i);
    }
    
//    for(int i =0 ; i < 100 ; i++ ) cout<<prm[i]<<" ";
//    cout<<'\n';
//
//    for(auto x: prm) cout<<x<<" ";
//    cout<<'\n';
}

int main()
{
    fastRead;
//    seive();    
    ll n;
    
    
//    ll ret = 1;
//    while(ret*3 < 1e12) ret *=3;
//    cout<<ret<<'\n';
//    return 0;
//    for(int j =1 ; j <=20 ; j++ ) {
        cin>>n;
    ll nn = n;
    
    ll till = sqrt(n) + 10;
    till = min(till , n);
    
    
    vector<ll>vec;
    
    for(ll i = 2 ; i < till ; i++ )  {
        
        if(n%i == 0 ) {
            vec.push_back(i);
            vec.push_back(n/i);
        }
    }
    
    if(vec.size() == 0 ) cout<<n<<'\n';
    else {
        
        ll gcd = vec[0];
        for(auto x : vec) gcd = __gcd(gcd , x);
        
        if(gcd == 1) cout<<1<<'\n';
        else cout<<gcd<<'\n';
    }
    
    
//    }
    
    return 0;
}