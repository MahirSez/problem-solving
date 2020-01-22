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
int ara[MAX];
int main()
{
    fastRead;
    int n , x;
    cin>>n>>x;
    int now = 0;
    int nn = 0;
    
    while(n--) {
        
        
        int y;
        cin>>y;
        y%= x;
        ara[y]++;
        
        
        while(ara[now]) {
            ara[now]--;
            now++;
            nn++;
            now%=x;
        }
        
        cout<<nn<<'\n';
    }
    return 0;
}