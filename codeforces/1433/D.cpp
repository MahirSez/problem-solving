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
    while(t--)   {
        int n;
        cin>>n;
        vector<int>vec(n+1);
        set<int>s;
        for(int i =1 ; i <=n ; i++ ) cin>>vec[i], s.insert(vec[i]);
        if(s.size() == 1) {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        int id1 = 1, id2 = -1;
        for(int i =2 ; i <= n ; i++ ) {
            if(vec[i] != vec[id1]) id2 = i;
        }
        
        for(int i =2 ; i <= n ; i++ ) {
            if(vec[i] == vec[id1]) cout<<id2<<" "<<i<<'\n';
            else cout<<id1<<" "<<i<<'\n';
        }

    
    }
    return 0;
}