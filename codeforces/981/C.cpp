#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , deg[MAX] ,fre[MAX] , tmp , cnt ;
vector<int>ones;
int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n -1 ; i++ ) {
        int u , v;
        cin>>u>>v;
        deg[u]++;
        deg[v]++;
    }
    for(int i =1 ; i <= n ; i++ ) {
        if( deg[i] == 1 ) ones.push_back(i);
        if( deg[i] > 2) cnt++;
    }
    if( cnt > 1) {
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    if( cnt == 1) {
        for(int i = 1 ; i<= n ; i++ ) {
            if( deg[i] > 2) {
                tmp = i;
                break;
            }
        }
        cout<<ones.size()<<endl;
        for(int i = 0 ; i < ones.size() ; i++) {
            cout<<tmp<<" "<<ones[i]<<endl;
        }
        return 0;
    }
    cout<<1<<endl;
    cout<<ones[0]<<" "<<ones[1]<<endl;
    return 0;
}
