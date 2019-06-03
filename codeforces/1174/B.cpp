#include <bits/stdc++.h>
#define ll          long long int
#define PI          acos(-1)
#define read        freopen("in.txt","r",stdin)
#define uu          first
#define vv          second
#define write       freopen("out.txt","w",stdout)
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define EPS         1e-8
#define MAX         1000006
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , ara[MAX];
int odd , ev;
int main()
{
    fastRead;
    cin>>n;
    for(int i= 0 ; i < n ; i++) {
        cin>>ara[i];
        if( ara[i] & 1) odd = 1;
        else ev = 1;
    }
    if( odd && ev) {
        sort(ara , ara + n);
    }
    for(int i = 0 ; i < n ; i++) {
        cout<<ara[i]<<" ";
    }
    cout<<'\n';
    
    return 0;
}