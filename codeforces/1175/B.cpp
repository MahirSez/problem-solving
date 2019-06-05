#include <bits/stdc++.h>
#define ll          long long int
#define PI          acos(-1)
#define read        freopen("in.txt","r",stdin)
#define uu          first
#define vv          second
#define write       freopen("out.txt","w",stdout)
#define pii         pair<int,int>
#define psl         pair<string ,ll>
#define INF         1e9
#define EPS         1e-8
#define MAX         1000006
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
string of = "OVERFLOW!!!";

const ll lim = (1LL<<32)-1;
int n;
ll ans , gun;
stack<psl>st ;
stack<ll> ss;
vector<psl>vec;


int main()
{
    fastRead;
    gun = 1;
    
    cin>>n;
    
    while( n-- ) {

        string s;
        cin>>s;
        ll tmp = 0;
        if( s == "for") {
            cin>>tmp;
        }
        
        if(s == "add" ||  s== "for") {
            st.push({s , tmp});
        }
        else if( s == "end") {
            
            if( !st.empty() && st.top().uu == "for") {
                st.pop();
            }
            else {
                st.push({s , tmp});
            }
        }
    }
    
    while( !st.empty() ) {
        vec.push_back(st.top());
        st.pop();
    }
    reverse(vec.begin() , vec.end());
    
    for(auto x : vec) {
//            cout<<x.uu<<" "<<x.vv<<endl;
//    continue;
//        cout<<" - "<<x.uu<<" "<<x.vv<<" "<<ans<<" "<<gun<<endl;
        
        if( x.uu == "add") {
            ans += gun;
            if( ans > lim) {
                cout<<of<<'\n';
                return 0;
            }
        }
        
        else if( x.uu == "for") {
            
            gun *= x.vv;
            ss.push(x.vv);
            if(gun > lim) {
                cout<<of<<'\n';
                return 0;
            }
        }
        
        else if( x.uu == "end") {
            gun/=ss.top();
            ss.pop();
        }
        
//        cout<<" -- "<<x.uu<<" "<<x.vv<<" "<<ans<<" "<<gun<<endl;
        
    }
    cout<<ans<<'\n';
    return 0;
    
}