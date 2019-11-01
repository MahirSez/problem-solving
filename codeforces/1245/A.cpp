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
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        ll a , b;
        cin>>a>>b;
        ll gcd = __gcd(a , b);
        if(gcd == 1) cout<< "Finite\n";
        else cout<<"Infinite\n";
    }
    return 0;
    
}