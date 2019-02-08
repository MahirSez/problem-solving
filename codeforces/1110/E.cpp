#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll			pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , a[MAX] , b[MAX] ;
vector<int>v1 , v2;
int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) cin>>a[i];
    for(int i =0 ; i < n ; i++ ) cin>>b[i];
    for(int i =1 ;  i< n ; i++ ) {
        v1.push_back(a[i] - a[i-1]);
        v2.push_back(b[i] - b[i-1]);
    }
    sort(v1.begin() , v1.end() ) ;
    sort(v2.begin() , v2.end() ) ;
    if( v1 != v2 || a[0] != b[0] || a[n-1] != b[n-1]) {
        cout<<"No"<<endl;
    }
    else cout<<"Yes"<<endl;
    return 0;
}