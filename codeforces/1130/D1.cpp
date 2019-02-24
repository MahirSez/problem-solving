#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e15
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , m;
vector<int>ara[6000];

ll solve(int st) {

    ll mx = 0;
    for(int i = 1; i <= n ; i++ ) {
        int sz = ara[i].size();
        if( sz==0 )continue;
        ll ret = (sz -1 ) * n;
        if( i < st) ret +=n;
        ll mn = INF;

        for(auto x : ara[i]) {
            
            ll tmp ;
            if( x < i) tmp = x + n - st;
            else tmp = x - st;
            // if( st == 3 && i == 2) cout<<endl<<tmp<<endl;
            mn = min(mn , tmp);
        }
        mx = max(mx , ret + mn);
    }
    return mx;
}


int main()
{
    fastRead;
    cin>>n>>m;
    for(int i =0 ; i < m ;i++ ) {
        int frm , to;
        cin>>frm>>to;
        ara[frm].push_back(to);
    }

    for(int i =1 ; i<= n ; i++ ) {
        cout<<solve(i)<<" ";
    }
    // cout<<solve(1)<<endl;
    cout<<endl;
    return 0;
}