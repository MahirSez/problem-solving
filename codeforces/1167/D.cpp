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
int n , ara[MAX];
string str;
int main()
{
	fastRead;
	cin>>n>>str;
	int cnt = 0;

    for(int i =0 ; i < n ; i++ ) {
        if( str[i] =='(') ara[i] = ++cnt;
        else ara[i] = cnt , cnt--;
    }

    for(int i =0 ; i < n ; i++ ) {
		cout<<(ara[i]&1);
    }
    cout<<endl;
}
