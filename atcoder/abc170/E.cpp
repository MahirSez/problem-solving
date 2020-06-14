#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 2e5 + 5;
set<pii>rec[MAX], glob;
int rat[MAX], now[MAX];

int main()
{
    fastRead;
    
    int n, q;
    cin>>n>>q;
    
    for(int i =1 ; i <=n ; i++ ) {
        cin>>rat[i]>>now[i];
        rec[ now[i] ].insert({rat[i], i});
    }
    
    for(int i = 1 ; i < MAX ; i++ ) {
        if(rec[i].empty() ) continue;
        pii get = *(rec[i].rbegin());
        glob.insert(get);
    }
    
    while(q--) {
        
        int id, newP ;
        cin>>id>>newP;
                
        glob.erase(*(rec[now[id]].rbegin()) );
        rec[now[id]].erase({rat[id], id});
        if(!rec[now[id]].empty() )
            glob.insert(  *(rec[now[id]].rbegin()) );
        
        if(!rec[newP].empty())
            glob.erase(  *(rec[newP].rbegin()) );
        rec[newP].insert({rat[id], id});
        glob.insert(*(rec[newP].rbegin()));
        
        now[id] = newP;
        
        
        cout<<(*(glob.begin())).uu<<'\n';
    }
    
    return 0;
    
    
}