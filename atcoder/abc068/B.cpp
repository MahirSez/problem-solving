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
int n,cnt=1;
int main()
{
    cin>>n;
    while(cnt<n){
        cnt<<=1;
    }
    if(cnt>n) cnt/=2;
    cout<<cnt<<endl;
    return 0;
}
