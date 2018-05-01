#include <bits/stdc++.h>
#define ll          long long int
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
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
ll n , q , tot ,rem , tmp;
ll ara[MAX] , sum[MAX];
vector<ll>v;
int main()
{
    fastRead;
    cin>>n>>q;
    for(int i =0 ; i < n ;i++ ) cin>>ara[i];
    sum[0] = ara[0];

    for(int i = 1 ; i < n ;i++ ) sum[i] = sum[i-1] + ara[i];

    for(int i = 0 ; i < n ;i++ ) {
        v.push_back(sum[i]);
    }

    rem = sum[n-1];
    ll till = 0;

    while( q-- ) {

        cin>>tmp;
        till += tmp;

        if( till >= sum[n-1]) {
            cout<<n<<endl;
            till = 0;
            continue;
        }

        int id = lower_bound(v.begin() , v.end(), till) - v.begin();

        if( sum[id] == till) {

            cout<<n - id-1<<endl;
        }
        else {

            cout<<n-id<<endl;
        }
//        cout<<rem<<" "<<till<<endl;

    }
    return 0;
}
