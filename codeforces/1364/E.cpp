#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;

int ask(int x, int y) {
    
    cout<<"? "<<x<<" "<<y<<endl;
    int ret;
    cin>>ret;
    return ret;
}

int main()
{
    int n;
    cin>>n;
    int a= 1, b = 2;
    int ab = ask(a, b);
    
    for(int i = 3 ; i <=n ; i++ ) {
        
        int bc = ask(b, i);
        if(ab > bc) {
            a = i;
            ab = bc;
        }
        else if(ab == bc) {
            b = i;
            ab = ask(a, i);
        }
    }
    
    for(int i = 1; i <=n ; i++ ) {
        
        if(i == a || i == b ) continue;
        
        int ai = ask(i, a);
        int bi = ask(i, b);
        if(ai == bi) continue;
        
        if(ai > bi) a = b;
        break;
    }
    
    vector<int>ans;
    for(int i = 1; i <=n ; i++ ) {
        if(i == a) ans.push_back(0);
        else ans.push_back(ask(i , a));
    }
    cout<<"! ";
    for(auto x : ans) cout<<x<<" ";
    cout<<endl;
    return 0;
}
