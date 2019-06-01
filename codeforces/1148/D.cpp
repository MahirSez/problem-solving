#include <bits/stdc++.h>
#define ll          long long int
#define PI          acos(-1)
#define read        freopen("in.txt","r",stdin)
#define uu          first
#define vv          second
#define write       freopen("out.txt","w",stdout)
#define pii         pair<int,int>
#define pip         pair<int,pii>
#define pll         pair<ll,ll>
#define INF         1e9
#define EPS         1e-8
#define MAX         1000006
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n ;
vector<pip>vec1 , vec2;
vector<int>tmp1 , tmp2;

bool comp1(pip id1 , pip id2) {

    return id1.vv.vv > id2.vv.vv ;
}

bool comp2(pip id1 , pip id2) {
    
    return id1.vv.vv < id2.vv.vv; 
}


int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) {
        int u , v;
        cin>>u>>v;
        if( u > v) vec2.push_back({i+1 , {u , v} });
        else vec1.push_back({i+1 , { u ,v} } );
    }
    
    sort(vec1.begin() , vec1.end() , comp1);
    sort(vec2.begin() , vec2.end() , comp2);
    
    if( vec1.size()> vec2.size()) {
        cout<<vec1.size()<<'\n';
        for(auto x : vec1) cout<<x.uu<<" ";
    }
    
    else  {
        cout<<vec2.size()<<'\n';
        for(auto x : vec2) cout<<x.uu<<" ";
    }
    cout<<'\n';
    return 0;
    
    
    
    
}