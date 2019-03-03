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
#define MAX     	100005
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n ,  m , k;
vector<pii>ara[10000];
int power[10000] , scl[1000];
int main()
{
    fastRead;
    cin>>n>>m>>k;
    for(int i =1 ; i <= n ;i++) {
        cin>>power[i];
    }
    for(int i =1 ; i <= n ; i++ ) {
        
        cin>>scl[i];
        ara[scl[i]].push_back({power[i] , i});
    }

    for(int i =1 ; i<= n ; i++ ) {
        sort(ara[i].rbegin() , ara[i].rend());
    }
    int ans =0;
    while( k -- ) {

        int tmp;
        cin>>tmp;
        int id = scl[tmp];

        if( ara[id][0].vv != tmp ) ans++;
    }
    cout<<ans<<endl;
    return 0;


}