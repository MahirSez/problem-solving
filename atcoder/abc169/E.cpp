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
int main()
{
    fastRead;
    int n;
    cin>>n;
    vector<int>op , cl;
    for(int i =0 ; i < n ; i++) {
        int x , y;
        cin>>x>>y;
        op.push_back(x);
        cl.push_back(y);
    }
    
    sort(op.begin() , op.end());
    sort(cl.rbegin() , cl.rend());
    
    int tgt = (n-1)/2;
    if(n%2) {
        cout<<cl[tgt] - op[tgt] + 1<<'\n';
    }
    else {
            
        int cl1 = cl[tgt] , cl2 = cl[tgt+1];
        int st1 = op[tgt] , st2 = op[tgt+1];
            
        cout<<(cl1 + cl2) - (st1 + st2) + 1<<'\n';
        
        
    }
    
    return 0;
    
    
    
    
    
    
}