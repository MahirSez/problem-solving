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
    int t;
    cin>>t;
    while(t--) {
        int n , m;
        cin>>n>>m;
        if(n == 1) cout<<0<<'\n';
        else if(n == 2) cout<<m<<'\n';
        else cout<<2*m<<'\n';
    }
    return 0;
}