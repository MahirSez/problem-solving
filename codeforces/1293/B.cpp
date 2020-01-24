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

double solve(int n , int s)  {

    double ret = 0;
    
    while(1) {
            
        if(s >= n ) {
            ret += 1;
            return ret;
        }
        
        ret += 1.00*s/n ;
        n -=s;
    }
    assert(0);
}


int main()
{
    int n;
    cin>>n;
    double ans = 0 ;
    int id = -1;
    
    for(int i =1;  i <=1 ; i++  ) {
        double tmp = solve(n , i);
        
        if(tmp > ans) {
            id = i;
            ans = tmp;
        }
    }
    cout<<setprecision(5)<<fixed<<ans<<'\n';
    return 0;
}