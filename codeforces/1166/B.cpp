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
int k , n , m;
char ara[] = { 'a', 'e', 'i', 'o' ,'u'};
int main()
{
    cin>>k;
	int n = -1, m = -1;

    for(int i = 1 ; i <= k ; i++ ) {

        if( i>= 5 && k%i == 0 && k/i >= 5 ) {
			n = i;
			m = k/i;
			break;
        }
    }
    if( n == -1) {
		cout<<-1<<endl;
		return 0;
    }

    for(int i =0 ; i < n ; i++ ) {

		for(int j =0 ; j < m ; j++ ) {

            cout<<ara[(j+i)%5];
		}

    }
    cout<<endl;
    return 0;
}
