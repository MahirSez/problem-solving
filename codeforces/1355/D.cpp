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
    int n , s;
    cin>>n>>s;
    int ones = n - 1;
    int baki = s - ones;
    
    if(baki > ones + 1) {
            
        cout<<"YES\n";
        while(ones--) cout<<1<<" ";
        cout<<baki<<'\n';
        cout<<baki-1<<'\n';
    }
    else cout<<"NO\n";
    return 0;
    
    
}