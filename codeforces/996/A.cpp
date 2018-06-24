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
int n;
int main()
{
    cin>>n;
    int cnt = 0;
    cnt += (n/100);
    n %= 100;
    cnt+= (n/20);
    n%=20;
    cnt+=(n/10);
    n%=10;
    cnt += (n/5);
    n%=5;
    cnt+=n;
    cout<<cnt<<endl;
    return 0;

}
