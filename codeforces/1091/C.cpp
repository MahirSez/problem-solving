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
ll n;
set<ll>dv;

ll getSum(ll x) {


    ll last = (n - x);

    ll tot = n/x ;

    ll ans =  (tot * (2 + (tot-1)*x) ) /2;
    return ans;

}
void pre() {

    ll rt = sqrt(n);
    for(int i =1 ; i<=rt ; i++ )  {

        if( n%i ==0 ) {


            dv.insert(n/i);
            dv.insert(i);
        }
    }
}

int main()
{

    cin>>n;
    pre();

    ll tmp = n;
    set<ll>s;

    for(auto x : dv) s.insert(getSum(x));
    for(auto x: s) cout<<x<<" ";
    cout<<endl;
    return 0;
}
