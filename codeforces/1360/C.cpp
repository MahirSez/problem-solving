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
        vector<int>vec(n);
        int odd =0 ;
        for(int i =0 ; i < n; i++ ) {
            cin>>vec[i];
            if(vec[i]%2) odd++;
        }
        
        sort(vec.begin() , vec.end());
        int ok = 0;
        for(int i = 0 ; i < n-1 ; i++ ) {
            if(vec[i]+1 ==  vec[i+1]) ok = 1;
        }
        
        if(odd%2 == 0 || ok ) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
    
}