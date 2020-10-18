#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define plp         pair<ll,pll>
#define tp          tuple<int,int,int>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

ll dst[10];

int dx[] = {-10 , -1 , -1 , 0 , 1 , 1 , 0};
int dy[] = {-10 , 1 , 0 , -1 , -1 , 0 , 1};
ll ara[10][10];

void change() {
    
    
    priority_queue<plp, vector<plp> , greater<plp> > pq;

    pq.push({0 , {1 , 1}});

    for(int i = 0 ; i <=5 ; i++ ) {
        for(int j =0 ; j <= 5 ; j++ ) ara[i][j] = INF;
    }

    ara[1][1] = 0;

    while(!pq.empty()) {
        plp top = pq.top();
        ll cst = top.uu;
        ll x = top.vv.uu;
        ll y = top.vv.vv;
        pq.pop();

        // cout<<x<<" "<<y<<" "<<ara[x][y]<<" "<<" "<<cst<<'\n';

        if(ara[x][y]  != cst) continue;

        for(int i = 1; i <= 6 ; i++ ) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            // cout<<xx<<" "<<yy<<'\n';

            if(xx <0 || yy <0 || xx >2 || yy > 2)  continue;


            if(cst + dst[i] < ara[xx][yy] ) {
                ara[xx][yy]  = cst + dst[i];
                pq.push({ara[xx][yy] , {xx,yy}});
            }
        }

    }


    
}

int main()  {
    fastio;


    int t;
    cin>>t;
    while(t--) {
        int x , y;
        cin>>x>>y;

        for(int i =1 ; i <= 6 ; i++ ) cin>>dst[i];
        change();
        
        

        dst[0] = ara[1][1];
        dst[1] = ara[0][2];
        dst[2] = ara[0][1];
        dst[3] = ara[1][0];
        dst[4] = ara[2][0];
        dst[5] = ara[2][1];
        dst[6] = ara[1][2];
        // for(int i =0 ; i <= 6 ; i++ ) cout<<dst[i]<<" ";
        // cout<<'\n';

        
        ll ans = 0;

        if(x == 0) {
            if(y > 0 ) ans = y*dst[2];
            else ans = -y*dst[5];
        }
        else if(y == 0) {
            if(x > 0 ) ans = x*dst[6];
            else ans = -x*dst[3];
        }
        else if(x>0 && y > 0 ) {
            ll mn = min(x, y);
            ans = mn * dst[1];
            x-=mn;
            y -=mn;
            ans += x*dst[6] + y*dst[2];
        }
        else if(x >0 && y < 0) {
            ans = x*dst[6] - y*dst[5];
        }
        else if(x <0 && y > 0) {
            ans = -x*dst[3] + y*dst[2];
        }
        else if(x <0 && y < 0) {
            x = -x;
            y = -y;
            ll mn = min(x , y );
            ans = mn*dst[4];
            x -= mn;
            y -= mn;
            ans += x*dst[3] + y *dst[5];
        }
        else assert(0);

        cout<<ans<<'\n';
    }
    return 0;
    
    
}