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
int n , q;
int ara[MAX] , ans1[MAX] , ans2[MAX];
int main()
{
    deque<int>dq;
    fastRead;
    cin>>n>>q;
    for(int i =0 ; i < n ; i++ ) {
        int tmp;
        cin>>tmp;
        dq.push_back(tmp);
    }
    
    for(int i =1 ; i < n; i++  ) {
        
        ans1[i] = dq.front(); dq.pop_front();
        ans2[i] = dq.front(); dq.pop_front();
        
        
        if( ans1[i] > ans2[i]) {
            dq.push_front(ans1[i]);
            dq.push_back(ans2[i]);
        }
        else {
            dq.push_front(ans2[i]);
            dq.push_back(ans1[i]);
        }
    }
    
    int top = dq.front();
    
    dq.pop_front();
    
    
    vector<int>vec;
    
    for(int i =0 ; i < n -1; i++ ) {
        vec.push_back(dq.front());
        dq.pop_front();
//        cout<<vec[i]<<" ";
    }
//    cout<<endl;
    
    while( q-- ) {
        
        ll id;
        cin>>id;
        
        if( id < n ) {
            cout<<ans1[id]<<" "<<ans2[id]<<'\n';
        }
        else {
            
            id-= n;
            
            id %= (n-1);
            
            cout<<top<<" "<<vec[id]<<'\n';
        }
    }
    return 0;
}



/*

5 15
7 9 3 5 10

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

*/