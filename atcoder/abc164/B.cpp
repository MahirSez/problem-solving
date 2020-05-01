#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int main()
{
    fastRead;
    int a , b , c , d;
    cin>>a>>b>>c>>d;
    
    for(int i =0 ; ; i++ ) {
        
        if(i%2 == 0 ) c -=b;
        else a -= d;
        
        if(a <= 0 ) {
            cout<<"No\n";
            break;
        }
        if(c <= 0)  {
            cout<<"Yes\n";
            break;
        }
    }
    return 0;
    
}