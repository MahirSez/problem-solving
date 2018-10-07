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
int n , ara[MAX] , rec[MAX];
int ans[MAX];
int main()
{
    fastRead;
    cin>>n;
    memset(ans ,-1 , sizeof ans);
    for(int i =1 ; i <= n ; i++ ) {
        cin>>ara[i];
        rec[ara[i]] = i;
    }
    if( n==1 ) {
        cout<<'B'<<endl;
        return 0;
    }
    ans[rec[1]] = 1;
    for(int i = n ; i>= 2 ; i--) {
        bool ok = false;
        for(int j = rec[i]  ; j <= n ;j+= i  ) {
            if( ans[j] == 0 && ara[j] > i) ok = true;
        }
        for(int j = rec[i]  ; j >=1 ;j-= i ) {
            if( ans[j] == 0 && ara[j] > i) ok = true;
        }
        ans[rec[i]] = ok;
    }
    for(int i = 1 ; i<= n ;i++ ) {
        if(ans[i]) cout<<'A';
        else cout<<'B';
    }
    cout<<endl;
    return 0;
}
