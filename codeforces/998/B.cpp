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
int n , B;
int ara[MAX] , odd , even;
vector<int>v;
int main()
{
    fastRead;
    cin>>n>>B;

    for(int  i= 0 ;i < n ; i++ ) {
        cin>>ara[i];
        if( ara[i] & 1) odd++;
        else even++;
    }
    if( odd!=even) {
        cout<<0<<endl;
        return 0;
    }
    odd =0 , even = 0;
    for(int i = 0 ; i < n-1 ; i++ ) {
        if( ara[i] & 1) odd++;
        else even++;
        if( odd == even) {
            v.push_back(abs(ara[i]-ara[i+1]) );
            odd= 0 ;
            even = 0;
        }
    }
    sort( v.begin() , v.end() ) ;
//    cout<<(int)v.size()<<endl;
    int cnt = 0 , taken = 0;
    for(int i =0 ; i < v.size() ; i++ ) {
        if( v[i] + taken > B) break;
        else {
            taken += v[i];
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
