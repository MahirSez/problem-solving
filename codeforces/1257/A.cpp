#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        int n , x , a , b;
        cin>>n>>x>>a>>b;
        if(a > b) swap(a , b);
        
        int dist = a - 1;
        int mn = min(dist , x);
        x -= mn;
        a -= mn;
        
        dist = n - b;
        mn = min(x ,dist);
        b += mn;
        cout<<b-a<<'\n';
    }
    return 0;
}