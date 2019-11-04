#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e3 + 3;
int ara[MAX] , vis[MAX];

int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        int n;
        cin>>n;
        for(int i=1 ; i <=n ; i++ ) {
            cin>>ara[i];
            vis[i] = 0;
        }
        
        for(int i = 1 ; i <= n ; i++ ) {
            
            int pos = -1;
            for(int j =1 ; j <=n ; j++ ) {
                if(ara[j] == i) pos = j;
            }
            pos--;
            
            while(pos>=1 &&  vis[pos] == 0 && ara[pos] > ara[pos+1] ) {
                
                swap(ara[pos] , ara[pos+1]);
                vis[pos] =1;
                pos--;
            }
        }
        
        for(int i =1;  i <=n ; i++ ) cout<<ara[i]<<" ";
        cout<<'\n';
    }
    return 0;
}