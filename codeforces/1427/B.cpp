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

    int t;
    cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;
        vector<int>vec;
        string s;
        cin>>s;
        int ans = 0;

        for(int i =0 ; i < n ; i++ ) {
            if(s[i] == 'W') {
                vec.push_back(i);
                ans++;
                if(i && s[i-1] == 'W') ans++;
            }
        }
        if(k ==0) {
            cout<<ans<<'\n';
            continue;
        }
        if(vec.size() == 0) {
            cout<<(k-1)*2 + 1<<'\n';
            continue;
        }
    
        vector<int>gaps, baki;

        for(int i =1 ; i < vec.size() ; i++ ) {
            if(vec[i] - 1 == vec[i-1]) continue;
            gaps.push_back(vec[i] - vec[i-1] - 1);
        }
        sort(gaps.begin() , gaps.end());

        
        int left = 0;

        for(auto x : gaps) {
            if(k >= x) {
                ans += 2*x + 1;
                k -= x;
            }
            else left += x;
        }

        left += vec[0];
        left += n - vec.back() - 1;
        left = min(left ,k);
        ans += left *2;
        cout<<ans<<'\n';

    }

    return 0;
    
}