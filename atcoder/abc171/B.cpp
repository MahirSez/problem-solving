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
    int n, k;
    cin>>n>>k;
    vector<int>vec(n);
    for(int i =0 ; i < n ; i++ ) cin>>vec[i];
    sort(vec.begin(), vec.end());
    ll sum =0 ;
    for(int i = 0 ; i < k ; i++) sum +=vec[i];
    cout<<sum<<'\n';
    return 0;
}