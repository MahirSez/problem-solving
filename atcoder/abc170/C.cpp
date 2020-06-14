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
    map<int,int>mp;
    int x, n;
    cin>>x>>n;
    for(int i =1 ; i <= n ; i++ ) {
        int tmp;
        cin>>tmp;
        mp[tmp] = 1;
    }
    
    int num = -200;
    
    for(int i = -200 ; i <= 200 ; i++ ) {
        
        if(mp[i]) continue;
        if(abs(i - x) < abs(num-x)) {
            num = i;
        }
    }
    cout<<num<<'\n';
    return 0;
    
}