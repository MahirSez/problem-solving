#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e18
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
ll fx , fy , tx , ty , n;
string str;


ll dirX[MAX] , dirY[MAX];


ll solve() {

    ll lo = 1 ,  hi = INF;
    ll ans = -1;

    while( lo <=hi ) {
        ll mid = (lo + hi)>>1;
        

        ll tmpX = fx + (mid/n) * dirX[n] + dirX[(mid%n)];
        ll tmpY = fy + (mid/n) * dirY[n] + dirY[(mid%n)];

        ll tmp = abs(tmpX - tx) + abs(tmpY - ty);
        // cout<<tmp<<" "<<mid<<endl;
        if( tmp <= mid ) {
            ans = mid;
            hi = mid-1;
        }
        else {
            lo = mid+1;
        }
    }
    return ans;
}


int main()
{
    fastRead;

    cin>>fx>>fy>>tx>>ty;
    cin>>n>>str;

    for(int i =0 ; i < str.size() ; i++ ) {

        dirX[i+1] = dirX[i];
        dirY[i+1] = dirY[i];

        if( str[i] == 'U') dirY[i+1]++;
        if( str[i] == 'D') dirY[i+1]--;
        if( str[i] == 'L') dirX[i+1]--;
        if( str[i] == 'R') dirX[i+1]++;

        // cout<<dirX[i+1]<<" "<<dirY[i+1]<<endl;
    }

    

    ll ans = solve();
    cout<<ans<<endl;
    return 0;
}