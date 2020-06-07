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
int main()
{
    fastRead;
    
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int>vec(n);
        int a = 0, b = 0;
        for(int i =0 ; i < n ; i++ ) cin>>vec[i];
        for(int i =0 ; i < n ; i++) {
            int tmp;
            cin>>tmp;
            if(tmp) a++;
            else b++;
        }
        if(a && b)  {
            cout<<"Yes\n";
            continue;
        }
        bool ok = 1;
        for(int i =1 ; i < n ; i++ ) {
            if(vec[i] < vec[i-1]) {
                ok = 0;
            }
        }
        if(ok) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
    
}