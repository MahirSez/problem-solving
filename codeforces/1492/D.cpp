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
    int z , o , k;
    cin>>z>>o>>k;
    int oo = o;
    int n = z + o;

    vector<int>a(n, -1) , b(n, -1); // a>= b

    if(k ==0) {
        string s = "";
        while(o--) s+='1';
        while(z--) s+='0';
        cout<<"Yes\n";
        cout<<s<<'\n';
        cout<<s<<'\n';
        return 0;
    }

    if(k > n - 2 ){
        cout<<"No\n";
        return 0;
    }
    
    a[n-1] = 1;
    b[n-1] = 1;
    o--;

    if(z == 0 || o  == 0) {
        cout<<"No\n";
        return 0;
    }


    a[0] = 0;
    b[0] = 1;
    a[k] = 1;
    b[k] = 0;
    z--;
    o--;

    for(int i = 0; i <n ; i++ ) {
        if(a[i] != -1) continue;
        if(z > 0) {
            a[i] = 0;
            b[i] = 0;
            z--;
        }
        else if(o > 0) {
            a[i] = 1;
            b[i] = 1;
            o--;
        }
        else assert(0);
    }

    
    int cnt = 0;
    for(auto x : a) cnt += x;
    assert(cnt == oo);
    // cout<<cnt<<'\n';


    cout<<"Yes\n";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for(auto x : a) cout<<x;
    cout<<'\n';
    for(auto x : b) cout<<x;
    cout<<'\n';



    return 0;
    
}