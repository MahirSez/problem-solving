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
int n , d , k;
vector<pii>v;
int ara[MAX];
int main()
{
    cin>>n>>d>>k;
    if( n == 1 ) {
        cout<<"NO"<<endl;
        return 0;
    }
    if( n == 2) {
        if( d!= 1 ) {
            cout<<"NO"<<endl;
        }
        else {
            cout<<"YES"<<endl;
            cout<<"1 2"<<endl;
        }
        return 0;
    }
    if( n >= 3) {
        if( d < 2 || k < 2 ) {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if( d + 1 > n ) {
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i = 1 ;i<= d ; i++ ) {
        v.push_back({i , i+1});
    }
    int till = d + 1;

    if( till == n ) {
        cout<<"YES"<<endl;
        for(int i = 0 ; i < v.size() ; i++ ) {
            printf("%d %d\n",v[i].uu, v[i].vv);
        }
        return 0;
    }

    int id = till+1;
    queue<pii>q;

    for(int i = 2 ; i < till ; i++ ) {
        q.push({i , min( i-1 , till - i) });
    }


    while( !q. empty() && id <= n ){

        int top = q.front().uu;
        int dia = q.front().vv;
        int deg ;
        if( top > till ) deg = 1;
        else deg = 2;
        if( deg >= k ) break;
        q.pop();
        for(int i = deg+1 ; i <= k && id <= n; i++ ,id++) {
            v.push_back({top , id});

            if(dia > 1 ) {
                q.push({id , dia-1});
            }
        }

    }
    if( id == n+1 ) {
        cout<<"YES"<<endl;
        for(int i = 0 ; i < v.size() ; i++ ) {
            printf("%d %d\n",v[i].uu, v[i].vv);
        }
    }
    else cout<<"NO"<<endl;

    return 0;
}

