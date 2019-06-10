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
int q ;
ll num;
int main()
{
    fastRead;
    cin>>q;
    while(q--) {
        cin>>num;
        int cnt = 0;
        while(1) {
            if( num%2==0) num/=2;
            else if( num%3 ==0) num = (num*2)/3;
            else if( num%5 ==0) num = (num*4)/5;
            else break;
            cnt++;
        }
        if( num == 1) {
            cout<<cnt<<'\n';
        }
        else cout<<-1<<'\n';
    }
    return 0;
}