#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	2e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n ;
int ara[MAX] , l[MAX] , r[MAX] , ans[MAX];
stack<int>s;
int main()
{
    fastRead;
    cin>>n;
    for(int i = 1 ; i<=n ; i++ ) {
        cin>>ara[i];
    }
    s.push(0);
    for(int i = 1 ;i<= n ;i++ ) {
        while( ara[s.top()] >= ara[i] ) {
            s.pop();
        }
        l[i] = s.top();
        s.push(i);
    }
    while( !s.empty() ) s.pop();

    s.push(n+1);

    for(int i = n ; i>=1 ; i-- ) {
        while( ara[s.top()] >= ara[i] ) {
            s.pop();
        }
        r[i] = s.top();
        s.push(i);
    }
//    for(int i =1 ; i <=n ; i++) {
//        cout<<ara[i]<<" "<<l[i]<<" "<<r[i]<<endl;
//    }

    for(int i = 1 ;i<= n ;i++) {
        int range = r[i] - l[i] - 1;
        ans[range] = max(ans[range] , ara[i]);
    }
    for(int i =n-1 ; i>=1 ; i--) {
        ans[i] = max( ans[i] , ans[i+1]);
    }
    for(int i= 1 ; i<= n ;i++ ) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
