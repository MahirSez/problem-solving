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
ll ara[20] , nw[20] , tmp ,sum , ans;
int main()
{
    for(int i =0 ; i < 14 ; i++ ) {
        cin>>ara[i];
    }

    for(int i =0 ; i < 14 ; i++ ) {
        ans  = 0;
        tmp = ara[i];
        memset( nw , 0 , sizeof nw);

        for(int j = i +1, cnt = 0; cnt < 14&& tmp > 0  ; j++ ,cnt++ ,tmp--) {
            if( (j)%14 == i)
                nw[(j)%14] = ceil(tmp*1.00 /14 );
            else
                nw[(j)%14] = ara[ (j)%14 ] + ceil(tmp*1.00 /14 );
        }
        for(int j =0 ; j < 14 ; j++ ) {

            if( nw[j]%2 == 0 ) ans += nw[j];
//            cout<<nw[j]<<" ";
        }
//        cout<<endl;
        sum = max(sum , ans);
    }
    cout<<sum<<endl;
}
