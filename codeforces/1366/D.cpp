#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 4000;
int mark[MAX];

vector<int>prm;

void seive() {
    
    for(ll i =2 ; i *i < MAX ; i++ ) {
        
        if(mark[i]) continue;
        for(ll j = i *i ; j < MAX; j +=i) {
            mark[j] = 1;
        }
    }
    
    for(int i = 2; i < MAX; i++) {
        if(mark[i] == 0 ) prm.push_back(i);
    }
    
//    cout<<prm.size()<<'\n';
}

int main()
{
    fastRead;
    seive();
    
    int n;
    cin>>n;
    vector<int>vec(n), ans1, ans2;
    for(int i =0 ; i  <n ; i++ ) cin>>vec[i];
    

    
    for(auto x : vec) {
        
        ll tmp = x;
        
        vector<int>rec;
        
        for(int i =0 ; i <prm.size() && tmp != 1  ; i++ ) {
            
            if(tmp%prm[i]) continue;
            
            int div = 1;
            while(tmp%prm[i] ==0 ) {
                tmp/= prm[i];
                div *= prm[i];
            }
            rec.push_back(div);
        }
        if(tmp!=1) rec.push_back(tmp);
        
        int d1 = 1, d2 = 1;
        
        for(int i =0 ; i < rec.size() ; i++) {
            
            if(i&1) d1*=rec[i];
            else d2*=rec[i];
        }
        
        if(d1 > 1 && d2 > 1 && __gcd(d1+ d2, x) == 1) {        
            ans1.push_back(d1);
            ans2.push_back(d2);
        }
        else {
            ans1.push_back(-1);
            ans2.push_back(-1);
        }
    }
    
    for(auto x: ans1) cout<<x<<" ";
    cout<<'\n';
    for(auto x: ans2) cout<<x<<" ";
    cout<<'\n';
    return 0;
}