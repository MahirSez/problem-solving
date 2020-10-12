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
int main() {
    fastio;

    int t;
    cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;
        ll tot = 0;
        vector<ll>vec(n);
        for(int i =0 ; i < n ; i++ ) cin>>vec[i] , tot += vec[i];
        if(tot == 0) {
            cout<<0<<'\n';
            continue;
        }
        sort(vec.rbegin() , vec.rend());

        for(int i =1 ; i < k+1 ; i++ ) {
            vec[0] += vec[i];
            vec[i] = 0;
        }
        sort(vec.rbegin() , vec.rend());
        cout<<vec[0] - vec.back()<<'\n';
    }
    return 0;
}