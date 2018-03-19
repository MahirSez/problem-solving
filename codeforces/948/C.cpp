#include <bits/stdc++.h>
#define ll			long long int
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
#define FastRead    ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
ll  n , v[MAX] , t[MAX] , lazy[MAX] ,tree[MAX], frm , to;
ll tsum[MAX], dayMelt[MAX];

void update(int node ,int b , int e) {

    if( frm > to || b > to || e < frm )
        return;
    if( b >= frm && e <= to ) {

        tree[node] += (e-b+1) ;
        lazy[node]++;
        return;
    }
    int mid = (b + e)>>1;
    update(node <<1 , b , mid);
    update(node<<1|1 , mid + 1, e);
    tree[node]  = tree[node<<1] + tree[node<<1|1];
}

ll query(int node ,int b , int e, ll carry) {

    if( b > to || e < frm ) return 0;

    if( b >=frm && e <= to) {

        return tree[node] += (e-b+1) * carry;
    }

    int mid = (b + e)>>1;
    ll q1 = query(node<<1 , b , mid , carry + lazy[node]);
    ll q2 = query(node<<1|1 , mid +1 , e ,carry + lazy[node]);
    return q1 + q2;
}
int main()
{
    FastRead;
    cin>>n;
    for(int  i =1 ; i <= n ; i++ )
        cin>>v[i];

    for(int  i =1 ; i <= n ; i++  )
        cin>>t[i] , tsum[i] += tsum[i-1] + t[i];

    for(int  i =1 ; i<= n ; i++ ) {

        ll lo = i , hi  =n , mid;
        frm = i , to = i-1;
        while( lo <= hi ) {
            mid = (lo + hi )>>1;

            ll melt = tsum[mid] - tsum[i-1];
            if( melt <= v[i]) {

                to = mid;
                lo = mid +1;
            }
            else {
                hi = mid-1;
            }
        }

        update(1,1,n);
        dayMelt[to+1] += v[i] - (tsum[to] - tsum[i-1]);
    }

    for(int  i= 1; i<=n ;i++ )  {
        frm = i,to= i;
        dayMelt[i] += query(1,1,n,0) * t[i];
        cout<<dayMelt[i]<<" ";
    }
    cout<<endl;
    return 0;
}
