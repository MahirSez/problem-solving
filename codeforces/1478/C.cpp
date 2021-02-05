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
        n += n;
        vector<ll>vec(n);
        for(int i =0; i < n ; i++ ) cin>>vec[i];
        sort(vec.rbegin() , vec.rend());

        int ok = 1;
        int baki = n ;
        ll sum = 0;
        set<int>st;

        for(int i =0; i < n ; i+=2) {

            if(vec[i] != vec[i+1]) ok = 0;

            vec[i] -= sum;

            if(vec[i] <= 0 || vec[i] % baki ) ok = 0;

            st.insert(vec[i]/baki);
            sum += 2*vec[i] / baki;
            baki-=2;
        }

        if(st.size() != n/2) ok = 0;
        // cout<<'\n';
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}