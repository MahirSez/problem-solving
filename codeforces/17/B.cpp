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
#define MAX     	10003
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , m ,ans;
int ara[MAX];
vector<int>edg[MAX];
int main()
{
    fastRead;
    cin>>n;
    for(int i =1 ; i<= n ; i++ ) cin>>ara[i];
    cin>>m;
    for(int i =0 ; i < m ; i++ ) {
        int a , b , w;
        cin>>a>>b>>w;
        edg[b].push_back(w);
    }
    bool ok = true;
    for(int i =1 ; i<= n ; i++) {
        if( edg[i].size()==0) {
            if( ok ) ok = false;
            else  {
                cout<<-1<<endl;
                return 0;
            }
        }
        else {
            sort(edg[i].begin() , edg[i].end());
            ans += edg[i][0];
        }
    }
    cout<<ans<<endl;
    return 0;
}
