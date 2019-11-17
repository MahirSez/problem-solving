#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
ll ara[MAX];
int main()
{
    fastRead;
    ll sum = 0;
    int n  , m;
    cin>>n>>m;
    
    vector<int>vec(n);
    for(int i =0 ; i  < n ; i++  ) {
        
        cin>>vec[i];
    }
    sort(vec.begin() , vec.end());
    for(int i =0 ; i < n ; i++ ) {
        
        ara[i%m] += vec[i];
        
        sum += ara[i%m];
        cout<<sum<<" ";
    }
    cout<<'\n';
    return 0;
}