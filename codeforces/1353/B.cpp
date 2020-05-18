#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

/*
1
2 1
1 2
3 4
*/

const int MAX = 1e6 + 6;
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        int n , k;
        cin>>n>>k;
        vector<int>v1(n) , v2(n) , tmp;
        for(int i =0 ; i < n ; i++ ) cin>>v1[i];
        for(int i =0 ; i < n ; i++ ) cin>>v2[i];
        sort(v1.begin() , v1.end());
        sort(v2.rbegin() , v2.rend());
        for(int i =0 ; i < k ; i++ ) tmp.push_back(v1[i]);
        for(int i =0 ; i < k ; i++ ) tmp.push_back(v2[i]);
        
        sort(tmp.rbegin() , tmp.rend());
        
        for(int i =0 ; i < k ; i++ ) v1[i] = tmp[i];

        int ans = 0;
        for(int i =0 ; i < n ; i++ ) ans += v1[i];
        cout<<ans<<'\n';
    }
    return 0;
}