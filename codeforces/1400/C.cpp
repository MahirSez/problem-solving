#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;
int main() {
    fastio;
    int t;
    cin>>t;
    while(t--) {
        string s;
        int x;
        cin>>s>>x;
        string w = "";
        int n = s.size();
        for(int i =0 ; i < s.size() ; i++ ) w += '1';


        for(int i =0 ; i < s.size() ; i++ ) {
            if(s[i] == '1') continue;
            if(i - x >=0 ) w[i-x] = '0';
            if(i + x < n ) w[i+x] = '0';
        }

        int ok = 1;
        for(int i =0 ; i < w.size() ; i++ ) {
            if(s[i] == '1') {
                
                int okk = 0;

                if(i-x >= 0 && w[i-x] == '1') okk =1;
                if(i+x < n && w[i+x] == '1')  okk =1;

                if(!okk) ok = 0;
            }
            else {

                int kk1= 0 , kk2 = 0;

                if(i-x >= 0 && w[i-x] == '1') kk1 =1;

                if(i+x < n && w[i+x] == '1')  kk2 =1;

                if(kk1 + kk2  > 0) ok = 0;
            }

        }
        if(ok) cout<<w<<'\n';
        else cout<<-1<<'\n';
    }
    return 0;
}