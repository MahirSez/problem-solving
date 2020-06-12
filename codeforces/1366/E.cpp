#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 2e5 + 5;
const ll MOD = 998244353;
/*
6 3
12 10 20 20 25 30
10 20 30
*/
int main()
{
    fastRead;
    int n, m;
    cin>>n>>m;
    vector<int>v1(n), v2(m), mn(n) , fst(m), s(m);
    for(int i =0 ; i < n ; i++ ) cin>>v1[i];
    for(int i =0 ; i < m ; i++ ) cin>>v2[i];
    
    mn[n-1] = v1[n-1];
    for(int i = n-2; i >=0 ; i--) {
        mn[i] = min(v1[i], mn[i+1]);
    }

    
    if(mn[0] != v2[0]) {
        cout<<0<<'\n';
        return 0;
    }
    
    
    int id = m-1;
    for(int j = n -1 ; j >=0 && id >=0; j--) {
        
        if(mn[j] == v2[id]) {
            fst[id] = j;
            id--;
        }
        else if(mn[j] < v2[id]) {
            cout<<0<<'\n';
            return 0;
        }
    }
    
    for(int i = m-1 ; i >=0 ; i-- ) {
        
        int lo = 0, hi = fst[i];
        
        while(lo<=hi) {
            int mid = (lo+hi)/2;
            if(mn[mid] >= v2[i]) {
                s[i] = mid;
                hi = mid-1;
            }
            else lo = mid + 1;
        }
    }
//    
//    for(int i =0 ; i < m ; i++ ) cout<<s[i]<<" "<<fst[i]<<'\n';
//    cout<<'\n';


    ll ans = 1;
    
    for(int i =1  ; i < m ; i++ ) {
        
        ll tmp = (fst[i] - s[i] + 1);
        ans = (ans * tmp) %MOD;
    }
    cout<<ans<<'\n';
    return 0;
}