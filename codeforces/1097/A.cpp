#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll         pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
string tgt;
int main()
{
    cin>>tgt;
    bool ok = false;
    for(int i =0 ; i < 5 ; i++) {
        string tmp;
        cin>>tmp;
        if( tgt[0] == tmp[0] || tgt[1] == tmp[1]) ok = true;
    }
    if( ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
