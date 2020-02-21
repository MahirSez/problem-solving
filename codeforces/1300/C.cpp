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
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i =0 ; i < n ;i++ ) cin>>vec[i];
    int id = -1;
    
    for(int i =30 ; i >=0  ; i-- ) {
        int cnt = 0;
        id = -1;
        
        for(int j =0 ; j < n ; j++ ) {
            if(vec[j] & (1<<i)) id = j , cnt ++;
        }
        if(cnt == 1) break;
    }
    
    if(id != -1) cout<<vec[id]<<" ";
    for(int i =0 ; i < n ;i++ ) {
        if(id == i ) continue;
        cout<<vec[i]<<" ";
    }
    cout<<'\n';
    return 0;   
    
}