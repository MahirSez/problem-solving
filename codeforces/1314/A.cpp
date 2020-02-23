#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;

bool comp(pii &p1 , pii &p2) {
    
    if(p1.uu == p2.uu) return p1.vv > p2.vv;
    return p1.uu < p2.uu;
}

int main()
{
    fastRead;
    int n;
    cin>>n;
    vector<pii>vec(n);
    
    for(int i =0 ; i < n ;i++ ) cin>>vec[i].uu ;
    for(int i =0 ; i < n ;i++ ) cin>>vec[i].vv;
    vec.push_back({2e9, 0});
    
    sort(vec.begin() , vec.end() );
    
//    for(auto x : vec) cout<<x.uu<<" "<<x.vv<<'\n';
    
    
    priority_queue<int>pq;
    
    ll sum = 0;
    ll inc = vec[0].vv;
    
    int last = vec[0].uu;
    pq.push(inc);
    
    
    for(int i =1 ; i <= n ; i++ ) {
        
            
        int frm = last ;
        int to = vec[i].uu-1;
        
//        cout<<inc<<" "<<sum<<'\n';
        
        for(int j = frm ; j <= to ; j++ ) {
//            cout<<j<<" ";
            
            if(pq.empty()) {
                assert(inc == 0);
                break;
            }
            inc -= pq.top();
            pq.pop();
            sum += inc;
//            cout<<" -- "<<inc<<'\n';
        }
        inc += vec[i].vv;
        pq.push(vec[i].vv);
        
        
        last = vec[i].uu;
    }
    
    
    
    
    cout<<sum<<'\n';
    return 0;
    
    
}

/*
7
2 2 2 3 3 3  5
3 4 100 1 2 100 2
*/
