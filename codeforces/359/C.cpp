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
ll n , x , ara[MAX] , sum  ;
priority_queue<ll , vector<ll> , greater<ll> > pq;

ll bigMod(ll a , ll b) {

    ll p ;
    if( b == 0) return 1;
    p = ( bigMod(a , b/2) % MOD );
    p = ( p * p) % MOD;
    if( b & 1 ) p = ( p * a) % MOD;
    return p;
}

int main()
{
    fastRead;
    cin>>n>>x;
    for(int i =0 ; i < n ; i ++ ) {
        cin>>ara[i];
        sum += ara[i];
    }
    for(int i =0 ; i < n ; i++ ) {
        pq.push(sum - ara[i]);
    }
    ll ans = 0;
    while( !pq.empty() ) {

        ll top = pq.top();
        pq.pop();
        bool done = true;
        int cnt = 1;
        while( !pq.empty() && pq.top() == top ) {
            ll tmp = pq.top();
            pq.pop();
            cnt++;
            if( cnt == x) {
                done = false;
                pq.push(top+1);
                break;
            }
        }

        if( done ) {
            ans= top;
            break;
        }
    }

    cout<<bigMod(x , min( ans , sum))<<endl;
    return 0;
}
