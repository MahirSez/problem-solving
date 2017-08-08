#include<bits/stdc++.h>
#define INF     1e9
#define ld      long double
#define lli     long long int
#define PI 	    acos(-1)
#define read    freopen("in.txt","r",stdin)
#define uu		first
#define vv		second
#define write   freopen("out.txt","w",stdout)
#define pii     pair<int,int>
using namespace std;
lli n,k,ara[100];
int main()
{
    //write;
	scanf("%lld",&k);
	//for(lli i=0;i<50;i++) ara[i]=i;
	n=50;
	lli tmp=k/n;
	for(lli i=0;i<n;i++) ara[i]=tmp+i;
	tmp=k%n;
	for(lli i=0;i<n;i++) {

		if(i<tmp) ara[i]+=(n+1);
		ara[i]-=(tmp);
	}
	printf("%lld\n",n);
	for(lli i=0;i<n;i++) printf("%lld ",ara[i]);
	return 0;
}
