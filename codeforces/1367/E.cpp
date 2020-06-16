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
int n, k;

int get(int per, vector<int>fre) {

    int ret = 0;
    for(int i = 1; i * per <= n ; i++ ) {
        
        int cnt = 0;
        
        for(int j =0 ; j < 30 ; j++ ) cnt += fre[j]/i;
        if(cnt >= per) ret = per * i;
    }
    return ret;
    
}

int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        string str;
        cin>>str;
        vector<int>fre(30);
        for(auto x : str) fre[x-'a']++;
        int ans = 0;
        
        for(int i =1 ; i <=k ; i++ ) {
            
            if(k%i) continue;
            int ret = get(i, fre);
            ans = max(ans, ret);
        }
        cout<<ans<<'\n';
    }
    return 0;
}