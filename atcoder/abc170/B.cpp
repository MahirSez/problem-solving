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
    int x, y;
    cin>>x>>y;
    if(y%2) {
        cout<<"No\n";
        return 0;
    }
    y/=2;
    int b = y - x;
    int a = x - b;
    if(a>=0 && b>=0) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
    
}