#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;


const int INF = 1e9;
const ll MOD = 1e9 + 7;
const int N = 2e5 + 5;
int ara[N], rec1[N], rec2[N];

int get(int x) {

    int ret = 0;
    while(x) {
        int bit = __builtin_popcount(x);
        x %= bit;
        ret++;
    }
    return ret;
}

/*
23
00110111001011011001110
*/


int main() {
    int n;
    string str;
    cin>>n>>str;

    int one = 0;
    for(auto x: str) {
        if(x=='1') one++;
    }
    if(one == 0 ) {
        cout<<1<<'\n';
        return 0;
    }

    int bp1 = max(one-1, 1), bp2 = one+1;

    int rem1 = 0;
    for(auto x : str) {
        rem1 *=2;
        if(x=='1') rem1++;
        rem1 %= bp1;
    }
    int rem2 = 0;
    for(auto x : str) {
        rem2 *=2;
        if(x=='1') rem2++;
        rem2 %= bp2;
    }

    rec1[0] = 1%bp1;
    rec2[0] = 1%bp2;
    for(int i =1 ; i < n ; i++ ) {
        rec1[i] = (rec1[i-1] * 2) % bp1;
        rec2[i] = (rec2[i-1] * 2) % bp2;
    }

    // cout<<one<<" "<<bp1<<" "<<bp2<<'\n';
    // cout<<rem1<<" "<<rem2<<'\n';
    
    vector<int>ans;

    for(int i =0, j = n-1 ; i < n ; i++, j-- ) {

        int tmp;
        if(str[i] == '1') {

            tmp = (rem1 - rec1[j] + bp1) % bp1;
        }
        else {

            tmp = ( rec2[j] + rem2) % bp2;
        }

        if(one == 1 && str[i] == '1') ans.push_back(0);
        else {
            tmp = get(tmp);
            ans.push_back(tmp + 1);
        }
    }

    for(auto x : ans) cout<<x<<'\n';
    return 0;

}