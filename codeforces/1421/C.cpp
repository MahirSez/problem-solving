#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define tp          tuple<int,int,int>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

vector<pii>ans;

string solve(int typ , int id , string s) {

    ans.push_back({typ , id});
    id--;

    string ss = "";
    if(typ == 1) {
        for(int i = 1 ; i <= id ; i++ ) ss += s[i];
        reverse(ss.begin() , ss.end());
        s = ss + s;
    }
    else {
        for(int i = id ; i < s.size()-1 ; i++ ) ss += s[i];
        reverse(ss.begin() , ss.end());
        s += ss;
    }
    return s;
}

int main()  {
    fastio;

    string s;
    cin>>s;
    int n;
    n = s.size();

    s = solve(1 , 2 , s);

    // cout<<s<<'\n';
    
    s = solve(2 , 3, s);
    s = solve(2 , 2 , s);
    s = solve(2 , s.size() -1 , s);


    string ss = s;
    reverse(ss.begin() , ss.end());

    assert(ss == s);

    // cout<<s<<" "<<ss<<'\n';

    
    cout<<ans.size()<<'\n';
    for(auto x : ans) {
        if(x.uu == 1) cout<<'L'<<" ";
        else cout<<'R'<<" ";
        cout<<x.vv<<'\n';
    }
    
    return 0;
}