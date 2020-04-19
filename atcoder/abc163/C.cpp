#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 3e5 + 5;

int main()
{
    fastRead;
    int n;
    cin>>n;
    vector<int>vec(n+1);
    for(int i =1 ; i < n ; i++ ) {
        int tmp;
        cin>>tmp;
        vec[tmp]++;
    }
    
    for(int i = 1 ; i <=n ; i++ ) cout<<vec[i]<<'\n';
    return 0;
}