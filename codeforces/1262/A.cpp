#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
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
        vector<int>vec1(n) , vec2(n);
        for(int i =0 ; i < n ; i++ ) {
            cin>>vec1[i]>>vec2[i];
        }
        sort(vec1.begin() , vec1.end());
        sort(vec2.begin() , vec2.end());
        int ans = vec1[n-1] - vec2[0];
        cout<<max(ans , 0)<<'\n';
    }
    return 0;
}