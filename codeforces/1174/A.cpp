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
int main()
{
    fastRead;
    cin>>n;
    for(int i= 0 ; i < 2*n ; i++) cin>>ara[i];
    sort(ara , ara + 2*n);
    int sum1 = 0 , sum2 = 0;
    for(int i =0 ; i < n ; i++  ) sum1 += ara[i];
    for(int i = n ; i <2 *n ; i++ ) sum2 += ara[i];
    
    if( sum1 == sum2) {
        cout<<-1<<'\n';
        return 0;
    }
    
    for(int i= 0 ; i < 2*n ; i++) {
        cout<<ara[i]<<" ";
    }
    cout<<'\n';
    return 0;
}