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
    vector<int>vec(MAX, 1);
    
    for(int i =2 ;i < MAX ; i++ ) {
        
        for(int j = i*2 ; j < MAX ; j += i ) {
            vec[j] = max(vec[j] , i);
        }
    }
    
    for(int i = 1; i < MAX ; i++ ) vec[i] = max(vec[i], vec[i-1]);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        cout<<vec[n]<<'\n';
    }
    return 0;
}