#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e18
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
 
const int MAX = 1e6 + 6;
int n , ara[MAX];
 
vector<int>vec , prm;
 
ll get(int sz) {
 
    int mid = sz/2;
    
    ll ret = 0;
    for(auto x : vec) ret += abs(x - vec[mid]);
    
    vec.clear();
    return ret;
 
}
 
 
 
ll solve(int div) {
 
    ll ret = 0;
    
    
    for(int i =1 ; i<=n ; i++ ) {
        
        if(ara[i]) vec.push_back(i);
        
        if(vec.size() == div ) {
            ret += get(div);
        }
    }
    
    return ret;
}
 
int main()
{
    fastRead;
    cin>>n;
    int num = 0;
    for(int i =1 ; i<=n ; i++ ) {
        cin>>ara[i];
        if(ara[i]) num++;
    }
    
    if(num == 1) {
        cout<<-1<<'\n';
        return 0;
    }
    
    
    for(int i =2 ; i <=num ; i++ ) {
        
        if(num%i ) continue;
            
        prm.push_back(i);
        
        while(num%i==0 ) num/=i;
    }
    
    ll ans = INF;
    for(auto x : prm) {
        
        ans = min(ans , solve(x) );
    }
    cout<<ans<<'\n';
    return 0;
    
    
}