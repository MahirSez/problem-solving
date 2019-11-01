#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9

#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const ll MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
string str;
vector<ll>vec;

ll dp[MAX];

int main()
{
    fastRead;
    
    dp[1] = 1;
    dp[2] = 2;
    for(int i =3 ; i <MAX ; i++ ) {
        
        dp[i] = (dp[i-1] + dp[i-2])%MOD;
    }
    
    cin>>str;
    
    
    str +='*';
    
    int n = str.size();
    int cnt = 0;
    
    for(int i =0 ; i < n ; i++ ) {
        
        if(str[i]!= 'u') {
            if(cnt > 0) vec.push_back(cnt);
            cnt = 0;
        }
        else cnt++;
        
        if(str[i] == 'w' || str[i] == 'm') {
            cout<<0<<'\n';
            return 0;
        }
    }
    cnt = 0;
    for(int i =0 ; i < n ; i++ ) {
        
        if(str[i]!= 'n') {
            if(cnt > 0) vec.push_back(cnt);
            cnt = 0;
        }
        else cnt++;
    }    
    
    ll ret = 1;
    
    for(auto x : vec) ret = (ret*dp[x])%MOD;
    cout<<ret<<'\n';
    return 0;
}