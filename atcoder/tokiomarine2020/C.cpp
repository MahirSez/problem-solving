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
    int n, k;
    cin>>n>>k;
    
    vector<int>vec(n);
    for(int i =0 ; i < n ; i++) cin>>vec[i];
    
    for(int i =0 ; i < k ; i++ ) {
        
        vector<int>tmp(n+1);
        
        for(int i= 0 ; i < n ; i++ ) {
            int l = max(0, i - vec[i]);
            int r = min(n-1, i + vec[i]);
            tmp[l]++;
            tmp[r+1]--;
//            cout<<i<<" -> "<<l<<" "<<r<<'\n';
        }
        for(int i =1 ; i < n ; i++ ) {
            tmp[i] += tmp[i-1];
        }
        for(int i =0 ; i < n ; i++ ) vec[i] = tmp[i];
        
        bool ok = 1;
        for(int i =0 ; i < n ; i++ ) {
            if(vec[i] != n ) ok = 0;
        }
        if(ok) break;
    }
    
    for(auto x : vec) cout<<x<<" ";
    cout<<'\n';
    return 0;
    
}