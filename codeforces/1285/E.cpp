#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;

/*
1
6
3 3
1 1
5 5
1 5
2 2
4 4
*/
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<pii>vec(n+1), rec;
        
        for(int i =1 ; i <= n ; i++ ) {
            cin>>vec[i].uu>>vec[i].vv;
            rec.push_back({vec[i].uu, -i});
            rec.push_back({vec[i].vv, i});
        }
        sort(rec.begin() ,rec.end());
        
        for(int i =0 ; i < 2*n; i++) {
            
            pii x = rec[i];
            if(x.vv < 0) vec[-x.vv].uu = i+1;
            else vec[x.vv].vv = i+1;
        }
        vector<int>fre(2*n+1), one(2*n+1), zero(2*n+1);
        for(int i =1 ; i <= n ; i++ ) {
            fre[vec[i].uu]++;
            fre[vec[i].vv]--;
        }
        
        for(int i = 1 ; i <= 2*n ;i++) {
            fre[i] += fre[i-1];
            one[i] += one[i-1];
            zero[i] += zero[i-1];
            
            if(fre[i] == 0) zero[i]++;
            else if(fre[i] == 1) one[i]++;
        }
        
//        for(int i= 1 ; i <= 2*n ; i++ ) {
//            cout<<zero[i]<<" ";
//        }
//        cout<<'\n';
//        for(int i= 1 ; i <= 2*n ; i++ ) {
//            cout<<one[i]<<" ";
//        }
//        cout<<'\n';        
        
        int ans = 0;
        for(int i =1 ; i <=n ; i++) {
            pii x = vec[i];
            int tmp = zero[x.uu] + zero[2*n] - zero[x.vv];
            tmp += one[x.vv-1] - one[x.uu];
            ans = max(tmp, ans);
        }
        cout<<ans<<'\n';
    }
    return 0;
}