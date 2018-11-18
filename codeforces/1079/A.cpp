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
int n , cnt[1000] , k , mark[1000] , tot;
int main()
{
    fastRead;
    cin>>n>>k;
    int mx = 0;
    for(int i =0 ; i < n ; i++ ) {
        int tmp ;
        cin>>tmp;
        cnt[tmp]++;
        mx = max(mx , cnt[tmp]);
        if( mark[tmp] ==0 ) {
            tot++;
            mark[tmp] = 1;
        }
    }

    int cl = (mx-1)/k + 1;

    int tgt = cl * k * tot;

    cout<<tgt - n<<endl;
    return 0;
}
