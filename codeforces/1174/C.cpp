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
#define MAX         100005  
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , mark[MAX];

void seive() {
    
    int cnt = 0;
    for(int i =2 ; i < MAX ; i++ ) {
        
        if( mark[i] ) continue;
        ++cnt;
        
        for(int j = 1 ; j *i < MAX ; j++) {
            mark[j*i] = cnt;
        }
         
    }
}

int main()
{
    seive();
    cin>>n;
    for(int i =2 ; i <= n ; i++ ) {
        cout<<mark[i]<<" ";
    }
    cout<<'\n';
    return 0;
    
}