#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;


int n ;
ll ara[MAX];
int main() {
    
    fastRead;
    cin>>n;
    
    for(int i =0 ; i < n; i++ ) cin>>ara[i];
    
    ll gcd = ara[0];
    
    for(int i =1 ; i < n ; i++ ) gcd = __gcd(gcd , ara[i]);
    
    
    set<ll>s;
    
    ll rt = sqrt(gcd) + 5;
    
    for(int i =1 ; i <= rt  ; i++ ) {
        
        if( gcd %i) continue;
        s.insert(i);
        s.insert(gcd/i);
    }
    cout<<s.size()<<'\n';
    
    return 0;
}