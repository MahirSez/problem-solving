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
int ara[MAX];
vector<int>v;
int n;
int main()
{
	fastRead;
	cin>>n;
	for(int i =0 ; i < n ; i++ ) {
		cin>>ara[i];
	}
	int last = ara[0];
	int cnt =1;
    for(int i =1 ; i < n ; i++ ) {

		if( last !=ara[i]) {
			v.push_back(cnt);
			cnt= 1;
			last = ara[i];
		}
		else cnt++;
    }

    v.push_back(cnt);

	int mx =0;
    for(int i =0 ; i < v.size()-1 ; i++ ) {
        mx = max(mx , min(v[i] , v[i+1])*2 );
    }
    cout<<mx<<endl;
    return 0;
}
