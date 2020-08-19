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

const ll N = 1e7 + 6;

int main()  {
    fastio;
    ll q;
    ll tmp;
    cin>>q;
    tmp = q;

    vector<ll>vec;

    for(int i =2 ; i < N ; i++ ) {
        while(q%i == 0) {
            vec.push_back(i) ;
            q/=i;
        }
    }

    if(q!= 1) vec.push_back(q);

    if(vec.size() <=1 ) {
        cout<<1<<'\n'<<0<<'\n';
        return 0;
    }
    if(vec.size() ==2 ) {
        cout<<2<<'\n';
        return 0;
    }

    ll ret = 1;
    cout<<1<<'\n';
    cout<<vec[0]*vec[1]<<'\n';
    return 0;
    

}