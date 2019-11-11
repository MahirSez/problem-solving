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
vector<int>vec[400];


int main()
{
    fastRead;
    int n;
    cin>>n;
    
    int cnt =0;
    
    for(int i =1 ; i <=n ; i++ ) {
        
        if(i&1) {
            
            for(int j =1 ;j <=n ; j++ ) vec[j].push_back(++cnt);
        }
        else for(int j =n ;j >=1 ; j-- ) vec[j].push_back(++cnt);
    }
    
    for(int i =1 ; i <=n ; i++ ) {
        for(auto x: vec[i]) cout<<x<<" ";
        cout<<'\n';
    }
    return 0;
    
}