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
int cnt1[MAX], cnt2[MAX], v1[MAX], v2[MAX], pos1[MAX], pos2[MAX];

int main()
{
    fastRead;
    int n;
    cin>>n;
    for(int i =0 ; i < n ;i++ ) {
        cin>>v1[i];
        pos1[v1[i]] = i;
    }
    for(int i =0 ; i < n ;i++ ) {
        cin>>v2[i];
        pos2[v2[i]] = i;
    }
    
    for(int i = n ; i < 2*n ; i++ ) v1[i] = v1[n-i];
    for(int i = n ; i < 2*n ; i++ ) v2[i] = v2[n-i];
    
    for(int i =0 ; i < n ; i++ ) {
        int id = v1[i];
        int p1 = i;
        int p2 = pos2[id];
        if(p2 < p1) p2 += n;
        
        cnt1[p2 - p1]++;
    }
    
    for(int i =0 ; i < n ; i++ ) {
        int id = v2[i];
        int p1 = i;
        int p2 = pos1[id];
        if(p2 < p1) p2 += n;
        
        cnt2[p2 - p1]++;
    }
    
    int ans =0;
    for(int i =0 ; i < MAX ; i++ ) ans = max(ans, cnt1[i]);
    for(int i =0 ; i < MAX ; i++ ) ans = max(ans, cnt2[i]);
    
    cout<<ans<<'\n';
    return 0;
    
    
    
    
}