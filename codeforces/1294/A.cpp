#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        int n , a  ,b , c;
        cin>>a>>b>>c>>n;
        int tot = a + b + c + n;
        if(tot%3) {
            cout<<"NO\n";
            continue;
        }
        tot/=3;
        if(a<=tot && b <= tot && c <=tot) cout<<"YES\n";
        else cout<<"NO\n";
        
    }
    return 0;
}