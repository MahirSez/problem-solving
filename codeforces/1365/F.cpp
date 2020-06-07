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
        vector<int>v1(n), v2(n);
        for(int i =0 ; i < n ; i++ ) cin>>v1[i];
        for(int i =0 ; i < n ; i++ ) cin>>v2[i];
        vector<int>tmp1 = v1;
        vector<int>tmp2 = v2;
        
        sort(tmp1.begin(), tmp1.end());
        sort(tmp2.begin(), tmp2.end());
        
        if(tmp1 != tmp2) {
            cout<<"No\n";
            continue;
        }
        
        if(n%2 && v1[n/2] != v2[n/2]) {
            cout<<"No\n";
            continue;
        }
        map<pii,int> mp1 , mp2;
        
        for(int i =0 , j = n-1 ; i < n/2 ; i++, j-- ) {
            
            if(v1[i] > v1[j]) swap(v1[i], v1[j]);
            mp1[{v1[i], v1[j]}]++;
            
            
            if(v2[i] > v2[j]) swap(v2[i], v2[j]);
            mp2[{v2[i], v2[j]}]++;
        }
        if(mp1 != mp2) cout<<"No\n";
        else cout<<"Yes\n";
    }
    return 0;
}