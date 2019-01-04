#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll         pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n;
set<string>s;
vector<pii>v;
map<pii , int>mp;


pii getVal(string tmp) {

    stack<char>st;
    int shuru = 0;
    int shesh = 0;

    for(auto x : tmp) {

        if( x== '(') {
            st.push(x);
            continue;
        }

        if( st.empty() ) {
            shesh++;
            continue;
        }

        st.pop();
    }

    while( !st.empty()) {
        st.pop();
        shuru++;
    }
//    cout<<tmp<<" "<<shuru<<" "<<shesh<<endl;
    return {shuru , shesh};


}

int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ;  i < n ; i++ ) {
        string tmp;
        cin>>tmp;

        pii val = getVal(tmp);
        if( val.uu >0 && val.vv > 0) continue;

        v.push_back(val);
        mp[val]++;
    }

    int ans = 0;
    for(auto x : v) {

        int f = x.uu;
        int s = x.vv;
        if( f==s) ans += mp[{f,s}]/2;
        else ans += min(mp[{f,s}] , mp[{s,f}]);
        mp[{f,s}] = 0;
        mp[{s,f}] = 0;
    }
    cout<<ans<<endl;
}
