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
int n ;
string str1 , str2;
int main()
{
    cin>>n;
    cout<<0<<" "<<0<<endl;
    cin>>str1;
    int lo = 0 , hi = 1e9;

    for(int i =0 ; i < n-1 ; i++ ) {
        int mid = (lo-hi)/2 + hi;
        cout<<mid<<" "<<1<<endl;
        cin>>str2;
        if( str2 == str1) lo = mid;
        else hi = mid;

    }
    cout<<lo<<" "<<2<<" "<<hi<<" "<<0<<endl;
    return 0;
}
