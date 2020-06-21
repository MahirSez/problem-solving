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
        vector<int>odd, ev;
        for(int i = 1 ; i <=2*n ; i++ ) {
            int tmp;
            cin>>tmp;
            if(tmp&1) odd.push_back(i);
            else ev.push_back(i);
        }
        
        if(odd.size()%2) odd.pop_back();
        if(ev.size()%2) ev.pop_back();
        
        int cnt = 0;
        
        for(int i =0 ; i < odd.size() && cnt < n-1; i+=2, cnt++) cout<<odd[i]<<" "<<odd[i+1]<<'\n';
        for(int i =0 ; i < ev.size() && cnt < n-1; i+=2, cnt++) cout<<ev[i]<<" "<<ev[i+1]<<'\n';
    }
    return 0;
    
}