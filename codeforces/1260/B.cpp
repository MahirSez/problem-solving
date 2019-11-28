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

        int a , b;
        cin>>a>>b;

        if(a < b ) swap(a , b);
        int diff = (a - b);
        b -= diff;
        a -= 2*diff;

        if(a >=0 &&  b>= 0 && (a+b)%3 ==0 ) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;

}
