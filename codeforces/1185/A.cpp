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
int a , b , c , d;
int main()
{
    vector<int>v;
    cin>>a>>b>>c>>d;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    sort(v.begin() , v.end());
    
    int diff1 = v[1] - v[0];
    int diff2 = v[2] - v[1];
    
    int ans1 = max( 0 , d - diff1) + max(0 , d - diff2);
    
    cout<<ans1<<endl;
    return 0;
}