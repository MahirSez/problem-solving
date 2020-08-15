#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

int main()  {
    fastio;
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i =0 ; i < n ; i++) cin>>vec[i];
    sort(vec.begin() , vec.end());
    int ans = 0;

    for(int i=0 ; i < n ; i++ ) {
        for(int j = i + 1; j < n  ; j++ ) {
            for(int k = j + 1; k < n ; k++ ) {

                if(vec[i] != vec[j] && vec[j] != vec[k] && vec[i] != vec[k] && vec[i] + vec[j] > vec[k]) ans++;
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
    
}