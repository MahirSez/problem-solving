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

/*
1
5 3
aabbc
*/
int main()
{
    fastRead;
    
    int t;
    cin>>t;
    while(t--) {
        int n , k;
        cin>>n>>k;
        string str;
        cin>>str;
        sort(str.begin() , str.end());
        
        
        
        if(k == n || str[0] != str[k-1]) {
            cout<<str[k-1]<<'\n';
            continue;
        }
        
        if( str[k] != str[n-1]) {
            cout<<str[0];
            for(int i = k ; i < n ; i++ ) cout<<str[i];
            cout<<'\n';
            continue;
        }
        
        int tmp = (n-k-1)/k + 1;
        
        cout<<str[0];
        while(tmp--) cout<<str[k];
        cout<<'\n';
    }
    return 0;
    
}