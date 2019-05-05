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
int n , m  , a1[100][100] , a2[100][100];

int main()
{
	fastRead;
	cin>>n>>m;
	for(int i =0 ; i < n ; i++ )
		for(int j = 0 ; j < m ; j++ ) cin>>a1[i][j];

	for(int i =0 ; i < n ; i++ )
		for(int j = 0 ; j < m ; j++ ) cin>>a2[i][j];

    for(int i =0 ; i < n ; i++ ) {
		for(int j =0 ; j < m ; j++ ) {
			if( a1[i][j] < a2[i][j]) {
				swap(a1[i][j] , a2[i][j]);
			}
		}
    }

    for(int i =0 ; i < n ; i++ ) {
		for(int j =1 ; j < m ;j++ ) {
			if( a1[i][j] <= a1[i][j-1] || a2[i][j] <=a2[i][j-1] ) {
				cout<<"Impossible"<<endl;
				return 0;
			}
		}
    }

    for(int j = 0 ; j < m ; j++ ) {
		for(int i =1 ; i < n ;i++ ) {
			if( a2[i][j] <= a2[i-1][j] || a1[i][j] <= a1[i-1][j] ) {
				cout<<"Impossible"<<endl;
				return 0;
			}
		}
    }

	cout<<"Possible"<<endl;
	return 0;
}
