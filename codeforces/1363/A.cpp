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
        int n, x;
        cin>>n>>x;
        int odd = 0 , ev = 0;
        for(int i =0 ; i < n ; i++ ) {
            int tmp;
            cin>>tmp;
            if(tmp&1 ) odd++;
            else ev++;
        }
        bool ok = 0;
        for(int i = 1 ;i<=x ; i+=2)  {
            if(i <=odd && x-i <= ev) ok = 1;
        }
        if(ok) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}