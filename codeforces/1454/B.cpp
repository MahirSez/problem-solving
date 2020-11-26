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
        int n;
        cin>>n;
        vector<int>rec(n+1), fre(n+1);

        for(int i =0 ; i < n ; i++ ) {
            int tmp;
            cin>>tmp;
            fre[tmp]++;
            rec[tmp] = i + 1;
        }
        int id = -1;

        for(int i = 1; i <= n ; i++ ) {
            if(fre[i] != 1) continue;
            id = rec[i];
            break;
        }
        cout<<id<<'\n';
        
    }
    return 0;
    
}