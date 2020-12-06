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
        ll d, k;
        cin>>d>>k;
        ll x = 0 , y = 0;
        for(int i =0 ; ; i++) {
            if(i%2 ==0) x += k;
            else y += k;
            if(x *x + y*y > d*d ) {
                if(i%2==0) cout<<"Utkarsh\n";
                else cout<<"Ashish\n";
                break;
            }
        }
    }
    return 0;
}