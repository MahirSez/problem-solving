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
        ll tot = 0;
        for(int i =0 ; i < n ; i++ ) {
            cin>>vec[i];
            tot += vec[i];
        }
        
        ll mxSum =0 , sum = 0;
        for(int i =0 ; i < n -1 ; i++ ) {
            sum += vec[i];
            mxSum = max(sum, mxSum);
        }
        sum = 0;
        reverse(vec.begin(), vec.end());
        for(int i =0 ; i < n -1 ; i++ ) {
            sum += vec[i];
            mxSum = max(sum, mxSum);
        }        
        if(mxSum >= tot) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}