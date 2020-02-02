#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pip         pair<int, pii >
#define pll         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int t;
const int MAX = 1e6 + 6;
int ara[MAX] ;
int main()
{
    fastRead;
    cin>>t;
    while(t-- ) {
        int n;
        cin>>n;
        vector<int>l(n) , r(n) , ans(n);
        for(int i =0 ; i < n ; i++ ) cin>>ara[i];
        
        int id = -1;
        
        for(int i = 0 ; i < n ; i++ ) {
            
            if(ara[i] < i) {
                id = i;
                break;
            }
            else ans[i] = i;
        }
        if(id == -1) {
            cout<<"Yes\n";
            continue;
        }
        
        bool ok = 1;
        for(int i = n-1 , j = 0 ; i >= id ; i-- , j ++) {
            
            if(ara[i] < j) {
                ok = 0;
                break;
            }
            else ans[i] = j;
        }
//        cout<<id<<'\n';
//        for(int i =0 ; i < n ; i++) cout<<ans[i]<<" ";
//        cout<<'\n';
        
        for(int i =0 ; i < n-1 ; i++ ) {
            if(ans[i] == ans[i+1] && ara[i] == ara[i+1])  ok = 0;
        }
        
        if(ok) cout<<"Yes\n";
        else cout<<"No\n";
        
    }
    return 0;
}

/*
1
4
0 1 1 0

*/