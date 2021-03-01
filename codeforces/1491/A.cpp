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

    int n, q;
    cin>>n>>q;
    vector<int>vec(n+1);
    int one = 0, zero = 0;
    for(int i =1 ;i <=n ; i++ ) {
        cin>>vec[i];
        if(vec[i]) one++;
        else zero++;
    }
    while(q--) {
        int typ, x;
        cin>>typ>>x;
        if(typ ==1 ) {
            vec[x] ^=1;
            if(vec[x] == 1) one++, zero--;
            else one--, zero++;
        }
        else {
            cout<<(one>=x)<<'\n';
        }
    }
    return 0;
}