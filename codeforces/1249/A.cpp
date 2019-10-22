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
int ara[200];
int main()
{
    int t;
    cin>>t;
    while(t--) {
        
        int n;
        cin>>n;
        for(int i =0 ; i < n ; i++ ) cin>>ara[i];
        sort(ara, ara  + n);
        int ans = 1;
        
        for(int i =1 ; i < n ; i++ ) {
            if(ara[i] == ara[i-1] + 1) {
                ans++;
                break;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}