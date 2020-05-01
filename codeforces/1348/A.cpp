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
        int n;
        cin>>n;
        ll sum1 = 0 , sum2 = 0;
        for(int i =1 ; i <=n/2-1 ; i++) {
            sum1 += (1LL<<i);
        }
        sum1 += (1LL<<n);
        for(int i = n/2 ; i < n ; i++) sum2 += (1LL<<i);
        cout<<abs(sum1-sum2)<<'\n';
    }
    return 0;
}