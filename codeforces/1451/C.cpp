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
        int n , k;
        cin>>n>>k;
        string s1 , s2;
        cin>>s1>>s2;
        vector<int>fre1(30), fre2(30);
        for(auto x : s1) fre1[x-'a']++;
        for(auto x : s2) fre2[x-'a']++;

        int ok = 1;

        for(int i =0 ; i < 29 ; i++ ) {

            if(fre1[i] < fre2[i]) ok = 0;
            fre1[i] -= fre2[i];
            if(fre1[i]%k) ok = 0;
            fre1[i+1] += fre1[i];
        }
        if(ok) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}