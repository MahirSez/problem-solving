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
int n;
int ara[MAX];
vector<int>vec;

int main()
{
    cin>>n;
    int sum = 0;
    for(int i =1 ; i <=n ; i++ ) cin>>ara[i] , sum += ara[i];
    int aa = ara[1];
    
    vec.push_back(1);
    int tot = ara[1];
    
    for(int i =2 ; i <=n ; i++ ) {
        
        if( ara[i]*2 <= aa ) {
            vec.push_back(i);
            tot += ara[i];
        }
    }
    
    if( tot * 2 > sum ) {
        
        cout<<vec.size()<<endl;
        for(auto x : vec) cout<<x<<" ";
        cout<<'\n';
        return 0;
    }
    
    cout<<0<<endl;
    return 0;
    
}