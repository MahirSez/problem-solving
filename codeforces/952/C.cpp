#include <bits/stdc++.h>
#define ll          long long int
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
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
int n ;
int ara[1000];
int main()
{
    cin>>n;
    for(int  i =0  ; i < n ; i++) {
        cin>>ara[i];
    }

    for(int i =0 ; i < n-1 ; i++ ) {

        if( abs(ara[i] -ara[i+1]) >=2 ) {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
