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
    ll n , m , q;
    cin>>n>>m>>q;
    
    ll gcd = __gcd(n , m);
    
    ll nn = n / gcd;
    ll mm = m / gcd;
    
//    cout<<nn<<" "<<mm<<endl;
    
    while( q-- ) {
        
        ll sx , sy , ex , ey;
        cin>>sx>>sy>>ex>>ey;
        
        ll id1 , id2;
        if( sx == 1) id1 = (sy-1)/nn + 1;
        else id1 = (sy-1)/mm + 1;
        
        if( ex == 1) id2 = (ey -1)/nn + 1;
        else id2 = (ey - 1)/mm + 1;
        
        
        
//        cout<<id1<<" "<<id2<<endl;
        if( id1 == id2) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}