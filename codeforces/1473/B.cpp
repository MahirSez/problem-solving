#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define tp          tuple<int,int,int>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

int main()  {
    fastio;
    int t;
    cin>>t;
    while(t--) {
        string s1, s2;
        cin>>s1>>s2;
        if(s1.size() < s2.size() ) swap(s1, s2);
        
        int ok = 1;
        for(int i =0 ;i < s2.size() ; i++ ) {
            if(s2[i] != s1[i]) ok = 0;
        }
        if(!ok) {
            cout<<-1<<'\n';
            continue;
        }

        
        string ss1 = s1;
        string ss2 = s2;

        while(ss1.size() != ss2.size()) {
            if(ss1.size() < ss2.size() ) ss1 += s1;
            else ss2 += s2;
        }

        if(ss1 == ss2) cout<<ss1<<'\n';
        else cout<<-1<<'\n';
    }
    return 0;

}