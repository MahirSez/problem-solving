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
int n , m;
vector<int>edg[MAX];


vector<int>v;
int cnt[MAX];


bool ok(int div) {


    for(int i = 0; i < n ; i++ ) {

		if( edg[i] != edg[(i+div)%n]) return false;
    }
    return true;

}

int main()
{
	fastRead;
	cin>>n>>m;
	for(int i =0 ; i < m ; i++ ) {

        int a , b;
        cin>>a>>b;

        if(a > b) swap(a,b);

        int dst = min(b - a , a - b + n) ;
        edg[a%n].push_back(dst);
        edg[b%n].push_back(dst);
	}


    for(int i = 0 ; i <n ; i++ ) {
        sort(edg[i].begin() , edg[i].end());
    }
//
//    for(int i =0 ; i < n ;i++ ) {
//		cout<<i<<endl;
//		for(auto x : edg[i]) cout<<x<<" ";
//		cout<<endl;
//    }

    for(int i = 1 ; i < n ; i++ ) {

        if(n%i) continue;

        if( ok(i) ) {
			cout<<"Yes"<<endl;
			return 0;
        }
    }

	cout<<"No"<<endl;
	return 0;

}
