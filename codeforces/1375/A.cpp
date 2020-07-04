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
        vector<int>vec(n);
        for(int i =0 ; i < n ; i++) cin>>vec[i];
        for(int i = 0 ; i < n ; i++) {
            if( i %2 ==0 && vec[i] < 0) vec[i]*=-1;
            else if(i%2 && vec[i] > 0) vec[i] *= -1;
        }
        for(auto x : vec) cout<<x<<" ";
        cout<<'\n';
    }
    return 0;
}