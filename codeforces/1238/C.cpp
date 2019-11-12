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
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        
        int h  , n;
        cin>>h>>n;
        vector<int>vec(n);
        for(int i = 0; i < n ; i++ ) cin>>vec[i];
        vec.push_back(0);
        
        int cnt = 0;
        
        for(int i = 1 ; i < n ; ) {
            
            if(vec[i+1] == vec[i]-1) {
                i+=2;
                continue;
            }
            cnt++;
            i++;
            
        }
        cout<<cnt<<'\n';        
    }
    return 0;
}