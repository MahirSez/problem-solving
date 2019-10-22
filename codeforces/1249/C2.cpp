#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
vector<ll>rec;

stack<int>vec;

void process() {

    
    while(1) {
        
        int top = vec.top();
        vec.pop();
        
        if(!vec.empty() && vec.top() == top+1) continue;
        vec.push(top+1);
        break;
    }
}

ll get( ){

    ll ret = 0;
    while(!vec.empty()) {
        
//        cout<<vec.top()<<" "<<rec[vec.top()]<<'\n';
        ret += rec[vec.top()];
        vec.pop();
    }
    return ret;
}


int main()
{
    
    rec.push_back(1);
    for(int i =1 ;  ; i++ ) {
        
        rec.push_back(rec[i-1]*3);
        if(rec[i] == 1350851717672992089) break;
    }
    int nn = rec.size();
    
    int q;
    cin>>q;
    
    while(q--) {
        bool ok = true;
        
        ll n;
        cin>>n;
        
        while(n > 0 && ok) {
            
            for(int i = nn-1 ; i >=0 ; i-- ) {
                
                if(rec[i] <= n) {
                    if(!vec.empty() && vec.top() == i) {
                        ok = false;
                        break;
                    }
                    vec.push(i);
                    n -= rec[i];
                    break;
                }
            }
        }
        
        
        
        if(!ok) process();
        
        cout<<get()<<'\n';
        
    }
    
    return 0;
}