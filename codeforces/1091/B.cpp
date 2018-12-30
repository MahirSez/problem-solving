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
#define MAX     	40000
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , x1[MAX] , y1[MAX], x2[MAX], y2[MAX];
map<int,int>mpx1 , mpy1 , tmpx1 , tmpy1;
int ansx  , ansy;
int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) {
        cin>>x1[i]>>y1[i];
    }
    for(int i =0 ; i < n ; i++ ) {
        cin>>x2[i]>>y2[i];
        tmpx1[x2[i]]++;
        tmpy1[y2[i]]++;
    }

    for(int i =0 ; i < n ; i++ ) {

        mpx1= tmpx1;
        mpy1= tmpy1;

        ansx = x1[0] + x2[i];
        ansy = y1[0] + y2[i];
//        cout<<"---"<<ansx<<" "<<ansy<<endl;
        bool ok = true;
        for(int j =0 ; j < n ; j++ ) {

            int tx = ansx - x1[j];
            int ty = ansy - y1[j];
//            cout<<" -- "<<tx<<" "<<ty<<" "<<mpx1[tx]<<" "<<mpy1[ty]<<endl;
            if( mpx1[tx] ==0 || mpy1[ty] ==0) {
                 ok = false;
                 break;
            }

            mpx1[tx]--;
            mpy1[ty]--;
        }
        if( ok) {
            cout<<ansx<<" "<<ansy<<endl;
            return 0;
        }
    }


}
