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
string s1 , s2;
int ara[MAX];
int main()
{
    fastRead;
    cin>>s1>>s2;
    
    int cnt= 0 , ans = 0;
    for(auto x : s2) {
        if( (x-'0') == 1 ) cnt++;
    }
    
    for(int i = 0 ; i < s1.size() ; i++ ) {
        ara[i+1] = (s1[i]-'0');
        ara[i+1] += ara[i];
    }
    cnt &=1;
    
    for(int frm = 0  , to = s2.size() ; to <= s1.size() ; frm ++ ,to++) {
        
        int tmp = ara[to] - ara[frm];
        tmp&=1;
        if( (tmp^cnt) ==0  ) ans++;
    }
    cout<<ans<<'\n';
    return 0;
    
    
}