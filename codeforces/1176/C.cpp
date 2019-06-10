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
#define MAX         500005
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , ara[MAX] , ans;
set<int>st[100];
int rec[] = {4,8,15,16,23,42 };

int main()
{
    fastRead;
    cin>>n;
    for(int i =1 ; i <= n ; i++ ) {
        cin>>ara[i];
        st[ara[i]].insert(i);
    }
    
//    for(int i = 0 ; i < 6 ; i++ ) {
//        for(auto x: st[rec[i]]) {
//            cout<<x<<" ";
//        }
//        cout<<endl;
//    }
    
    while(1) {
        int pos = 0;
        bool ok = true;
    
        for(int i =0 ; i < 6 ; i++)  {
            
            int num = rec[i];
            
            auto it = st[num].begin();
            
            
            while( !st[num].empty() && *st[num].begin() < pos ) {
                st[num].erase(*st[num].begin() );
                
            }
            
            if( st[num].empty() ) {
                ok = false;
                break;
            }
            
            pos = *st[num].begin();
            st[num].erase(*st[num].begin() );
        }
        
        if( !ok ) {
            cout<<n - ans * 6<<'\n';
            return 0;
        }
        ans++;
    }
    return 0;
}