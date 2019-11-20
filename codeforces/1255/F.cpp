#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e18
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
 
const int MAX = 1e6 + 6;

int n ;
vector<int>ans;

ll ask(int a , int b , int c , int d) {
    
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    ll ret;
    cin>>ret;
    return ret;
}

void solve(vector<pll> & vec) {
    
    if(vec.size() ==0 ) return;
    
    sort(vec.rbegin() , vec.rend());
    
    int id1 = 1;
    int id2 = vec[0].vv;
    
    vector<pll>pos , neg;
    
    
    for(int i = 1; i < vec.size() ; i++ ) {
        
        ll sign = ask(2 , id1 , id2 , vec[i].vv);
        if(sign < 0 ) neg.push_back(vec[i]);
        else pos.push_back(vec[i]);
    }
    
    reverse(neg.begin() , neg.end());
    
    for(auto x : neg )  ans.push_back(x.vv);
    ans.push_back(id2);
    for(auto x : pos) ans.push_back(x.vv);
    
}

int main()
{
    cin>>n;
    
    int id1 = 1 , id2 = 2;
    vector<pll> pos , neg;
    
    for(int i =3; i <=n ; i++ ) {
        
        ll sign = ask(2 , id1 , id2 , i);
        ll area = ask(1 , id1 , id2 , i);
        
        if(sign > 0) pos.push_back({area , i});
        else neg.push_back({area , i});
    }
    
    ans.push_back(id1);
    solve(neg);
    ans.push_back(id2);
    solve(pos);
    
    cout<<"0 ";
    for(auto x : ans) cout<<x<<" ";
    cout<<endl;
    return 0;
    
}