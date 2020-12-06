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
        int n;
        cin>>n;
        vector<int>vec(n), fre(n+1);
        deque<int>dq;
        for(int i =0 ; i< n ;i++ ) {
            cin>>vec[i];
            dq.push_back(vec[i]);
            fre[vec[i]]++;
        }
        string ans = "";

        for(int i =1 ; i <=n ; i++ ) {

            if(fre[i] == 0) break;

            ans += '1';
        
            if(dq.front() == i || dq.back() == i) {
                if(dq.front() == i) dq.pop_front();
                else dq.pop_back();
                fre[i]--;
                if(fre[i]) break;                
            }
            else break;

        }
        while(ans.size() < n) ans += "0";
        reverse(ans.begin() , ans.end());

        int ok = 1;
        sort(vec.begin() , vec.end());
        for(int i = 0;i < n ; i++ ) {
            if(vec[i] != i+1) ok =0;
        }
        if(ok) ans[0] = '1';

        

        cout<<ans<<'\n';
        
    }
    return 0;
}