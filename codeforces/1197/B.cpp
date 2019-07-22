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
int n  , ara[MAX];
stack<int>st1  ,st2 ;
int main()
{
    fastRead;
    cin>>n;
    int id = -1;
    for(int i =0 ; i < n ; i++ ) {
        cin>>ara[i];
        if( ara[i] == n ) id = i;
    }
    
    for(int i =0 ; i <= id ; i++ ) {
        st1.push(ara[i]);
    }
    
    for(int i = n-1 ; i >  id ; i-- ) {
        st2.push(ara[i]);
    }
    
    int tgt = n;
    
    while( tgt > 0 ) {
        
        if(!st1.empty() && st1.top() == tgt) {
            st1.pop();
            tgt--;
        }
        else if(!st2.empty() && st2.top() == tgt) {
            st2.pop();
            tgt--;
        }
        else {
            
            cout<<"NO"<<'\n';
            return 0;
        }
    }
    cout<<"YES\n";
    return 0;
} 