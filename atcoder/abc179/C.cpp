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

int main()  {
    fastio;
    int n;
    cin>>n;
    vector<int>vec(n+1);
    for(int i =1 ; i < n ; i++ ) {
        for(int j = i ; j < n ; j+=i) vec[j]++;
    }

    int tot = 0;
    for(auto x : vec) tot += x;
    cout<<tot<<'\n';
    return 0;
    
    
}