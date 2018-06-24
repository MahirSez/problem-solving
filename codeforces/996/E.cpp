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
int n ,d[MAX];
ll x[MAX] , y[MAX];
vector<int>v;
int main()
{
    fastRead;
    srand(time(NULL));
    cin>>n;
    for(int i =0 ; i < n ; i++ ) {
        cin>>x[i]>>y[i];
        v.push_back(i);
    }
    ll lim = (1500000);
    lim *= lim;
    while( 1 ) {
        random_shuffle(v.begin() , v.end() ) ;
        ll sumx = 0 , sumy = 0;
        for(int i =0 ; i < n ; i++ ) {
            ll tmpx1 = sumx + x[v[i]];
            ll tmpy1 = sumy + y[v[i]];
            ll tmpx2 = sumx - x[v[i]];
            ll tmpy2 = sumy - y[v[i]];
            ll tmp1 = tmpx1 * tmpx1 + tmpy1 * tmpy1;
            ll tmp2 = tmpx2 * tmpx2 + tmpy2 * tmpy2;
            if( tmp1 <= tmp2 ) {
                sumx = tmpx1;
                sumy = tmpy1;
                d[v[i]] = 1;
            }
            else {
                sumx = tmpx2;
                sumy = tmpy2;
                d[v[i]] = -1;
            }
        }
        ll tmp = sumx * sumx + sumy * sumy;
        if( tmp <= lim) break;
    }
    for(int i =0 ; i < n ; i++ ) {
        cout<<d[i]<<" ";
    }
    cout<<endl;
    return 0;
}
