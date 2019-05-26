#include <bits/stdc++.h>
#define ll          long long int
#define PI          acos(-1)
#define read        freopen("in.txt","r",stdin)
#define uu          first
#define vv          second
#define write       freopen("out.txt","w",stdout)
#define pii         pair<int,int>
#define ppi         pair<pii,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define EPS         1e-8
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int N = 3e5+5;

int  n , m , ara[N] , aux[N];


bool ok(int key) {


    for(int i =0 ; i < n ; i++ ) aux[i] = ara[i];

    int prev = 0;

    for(int i =0 ; i< n ; i++ ) {

        if( aux[i] + key < prev) return false;

        if( prev > aux[i] ) {
            aux[i] = prev;
        }
        else {

            if( m - aux[i] + prev <= key) aux[i] = prev;
        }

        prev = aux[i];
    }
    return true;
}

int main()
{

    fastRead;
    cin>>n>>m;
    for(int i =0 ; i < n ; i++ ) cin>>ara[i];

    int lo = 0 , hi = 1e6;
    int ans = -1;

    while( lo<=hi) {

        int mid = (lo+hi)>>1;
        if( ok(mid)) {
            ans = mid;
            hi = mid-1;
        }
        else {
            lo = mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
