#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int, pair<int,int> >
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	100005
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , k ;
int ara[2][MAX];
int  dst[2][MAX];
string str ;


bool solve() {
    priority_queue<pii , vector<pii> , greater<pii> > pq;
    pq.push(make_pair(0 , make_pair(0,0) ));
    while( !pq.empty() ) {
        int tim = pq.top().uu;
        int x = pq.top().vv.uu;
        int y = pq.top().vv.vv;
//        cout<<x<<" "<<y<<" "<<tim<<endl;
        pq.pop();
        if( y + k >=n )  return true;

        if( ara[x][y+1] != -1 && dst[x][y+1] > tim+1 ) {
            dst[x][y+1] = tim+1;
            pq.push(make_pair(tim+1 , make_pair(x,y+1)));
        }
        if( y > 0 && ara[x][y-1] != -1 && dst[x][y-1] > tim+1 && tim+1 <= y-1) {
            dst[x][y-1 ] = tim+1;
            pq.push(make_pair(tim+1 , make_pair(x,y-1)));
        }
        if(ara[x^1][y+k] != -1 && dst[x^1][y+k] > tim+1) {
            dst[x^1][y+k] = tim+1;
            pq.push(make_pair(tim+1 , make_pair(x^1,y+k)));
        }
    }
    return false;
}

int main()
{
    fastRead;
    cin>>n>>k;
    cin>>str;
    for(int i =0 ; i < n ; i++ ) if( str[i] =='X') ara[0][i] = -1;
    cin>>str;
    for(int i =0 ; i < n ; i++ ) if( str[i] =='X') ara[1][i] = -1;
    for(int i =0 ; i < n ; i++ ) dst[0][i] = INF , dst[1][i] = INF;
    bool ok = solve();
    if( ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}

