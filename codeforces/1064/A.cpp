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
int  a , b , c;
int main()
{
    int mx = 0;
    cin>>a>>b>>c;
    mx = max(mx , c-(a+b)+1);
    mx = max(mx , a-(b+c)+1);
    mx = max(mx , b-(a+c)+1);
    cout<<mx<<endl;
    return 0;
}
