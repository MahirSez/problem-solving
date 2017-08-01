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
int n,m,a,b,ara[200005];
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++) {
        scanf("%d %d",&a,&b);
        if(a==1 || a==n) ara[b]++;
        else if (b==1 || b==n) ara[a]++;
        if(ara[a]==2 || ara[b]==2) {
            printf("POSSIBLE\n");
            return 0;
        }
    }
    printf("IMPOSSIBLE\n");
    return 0;
}
