#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define tp          tuple<int,int,int>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

int main()  {
    fastio;
    int n;
    cin>>n;
    int cnt= 0;
    for(int i =0 ; i < n ; i++ ) {
        int a , b;
        cin>>a>>b;
        if(a == b ) cnt++;
        else cnt = 0;
        if(cnt == 3) {
            cout<<"Yes\n";
            return 0;
        }
        
    }
    cout<<"No\n";
    return 0;

    
    
}