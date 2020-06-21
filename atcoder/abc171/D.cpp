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
    int n;
    cin>>n;
    vector<int>fre(MAX);
    ll sum = 0;
    for(int i =0 ; i < n ; i++ ) {
        int tmp;
        cin>>tmp;
        sum += tmp;
        fre[tmp]++;
    }
    
    int q;
    cin>>q;
    while(q--) {
        int b, c;
        cin>>b>>c;
        sum -= 1LL*b*fre[b];
        sum += 1LL*c*fre[b];
        fre[c] += fre[b];
        fre[b] = 0;
        cout<<sum<<'\n';
    }
    return 0;
}