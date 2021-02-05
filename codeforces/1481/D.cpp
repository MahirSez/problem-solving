#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pip         pair<int,pii>
#define pll         pair<ll,ll>
#define tp          tuple<int,int,int>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e3 + 6;

int ara[N][N];

int n, m;

pii get1() {

    for(int i =0; i <n ; i++ ) {
        
        for(int j =0; j < n ; j++ ) {
            
            if(i ==j) continue;
            if(ara[i][j] == ara[j][i]) return {i+1, j+1};
            if(m %2) return {i+1 , j+1};
        }
    }
    return {-1,-1};
}

pip get2() {

    for(int i =0; i <n ; i++ ) {
        
        vector<int>zo , oz;

        for(int j =0; j < n ; j++ ) {
            
            if(i ==j) continue;
            assert(ara[i][j] != ara[j][i]);
            if(ara[i][j] == 0) zo.push_back(j);
            else oz.push_back(j);
        }

        if(zo.size() > 0 && oz.size() > 0 ) return {i+1, {zo[0]+1, oz[0]+1}};
    }
    assert(n == 2);
    return {-1, {-1,-1}};
}

int main()  {
    fastio;

    int t;
    cin>>t;
    while(t--) {
        
        cin>>n>>m;
        for(int i =0; i <n ; i++ ) {
            string s;
            cin>>s;
            for(int j =0; j < n ; j++ ) {
                if(s[j] == 'a') ara[i][j] = 0;
                else if(s[j] == 'b') ara[i][j] = 1;
                else ara[i][j] = -1;
            }
        }
        pii ret = get1();

        // cout<<" "<<ret.uu<<" "<<ret.vv<<'\n';
        if(ret != pii(-1,-1)) {
            cout<<"YES\n";
            m++;
            while(m--) {
                if(m%2) cout<<ret.uu<<" ";
                else cout<<ret.vv<<" ";
            }
            cout<<'\n';
            continue;
        } 
        assert(m%2 == 0);
        pip ret1 = get2();
        if(ret1.uu == -1) {
            cout<<"NO\n";
            continue;
        }
 
        cout<<"YES\n";
        int mid = ret1.uu;
        int a = ret1.vv.uu;
        int b = ret1.vv.vv;

        vector<int>ans;

        if( (m/2) %2 == 0) {
            for(int i =0 ; i< m/2 ; i++) {
                if(i%2 == 0) ans.push_back(mid);
                else ans.push_back(a);
            }
            ans.push_back(mid);
            for(int i = 0; i< m/2 ; i++ ) {
                if(i%2 == 0) ans.push_back(b);
                else ans.push_back(mid);            
            }
        }
        else {
            for(int i =0 ; i< m/2 ; i++) {
                if(i%2) ans.push_back(mid);
                else ans.push_back(a);
            }
            ans.push_back(mid);
            for(int i = 0; i< m/2 ; i++ ) {
                if(i%2==0) ans.push_back(b);
                else ans.push_back(mid);            
            }
        }

        for(int i =1 ; i <ans.size() ; i++ ) {
            assert(ans[i] != ans[i-1]);
        }
        for(auto x : ans) cout<<x<<" ";
        cout<<'\n';
    }
    return 0;
}