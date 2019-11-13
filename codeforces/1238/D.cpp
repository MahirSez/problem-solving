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

vector<int>vec;

int main()
{
    fastRead;
    ll n;
    string str;
    cin>>n>>str;
    str += '*';
    
    int cnt = 0;
    for(int i =0 ; i <n ; i++  ) {
        
        cnt++;
        if(str[i]!= str[i+1]) {
            vec.push_back(cnt);
            cnt =0;
        }
    }
    
//    for(auto x : vec)cout<<x<<" ";
//    cout<<'\n';
    ll ans = 0;
    for(int i= 0 ; i < vec.size()-1 ; i++) {
        
        ans += vec[i] + vec[i+1]-1;
    }
    ans = (n*(n-1))/2 - ans;
    
    cout<<ans<<'\n';
    return 0;
}