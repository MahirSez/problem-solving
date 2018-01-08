#include <bits/stdc++.h>
#define ll      long long int
#define PI      acos(-1)
#define read    freopen("in.txt","r",stdin)
#define uu      first
#define vv      second
#define write   freopen("out.txt","w",stdout)
#define pii     pair<int,int>
#define INF     1e9
#define EPS		1e-8
#define MAX		1000006
#define MOD		1000000007
using namespace std;
int n;
vector<int>edg[10000];
bool lf[10000];
int main()
{
    cin>>n;
    for(int  i =0 ; i < 10000; i++ ) lf[i] = true;
    for( int  i =2 ; i <=n ; i++ ){

        int tmp;
        cin>>tmp;
        edg[tmp].push_back(i);
        lf[tmp] = false;
    }
    bool flg = true;
    for( int  i =1 ; i<=n ; i++ ){

        int cnt = 0;

        for( int j =0 ; j < edg[i].size() ; j++ ){

            int node = edg[i][j];
            if( lf[node]) cnt++;
        }
        if( !lf[i] && cnt < 3) flg = false;
    }

    if( flg ) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
