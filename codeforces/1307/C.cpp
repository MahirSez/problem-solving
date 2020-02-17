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

ll rec[30];
int main()
{
    fastRead;
    
    string str;
    cin>>str;
    int n = str.size();
    ll ans = 0;
    
    for(auto x : str) {
        rec[x - 'a']++;
    }
    
    for(int i =0 ; i < 30 ; i++ ) ans = max(ans , rec[i]);
    
    for(int i =0 ; i < 26 ; i++ ) {
        
        for(int j = 0 ; j < 26 ; j++ ) {
            

            ll cnt1 = rec[i];
            ll cnt2 = rec[j];
            
            if(i == j ) {
                ans = max(ans , cnt1*(cnt1-1)/2 );
                continue;
                
            }
            
            
            ll tmp = 0;
            
            for(auto x : str) {
                
                int id = x-'a';
                if(id == i ) tmp += cnt2;
                if(id == j ) cnt2--;
            }
            
            ans = max(ans , tmp);
        }
    }
    
    
    cout<<ans<<'\n';
    return 0;
}