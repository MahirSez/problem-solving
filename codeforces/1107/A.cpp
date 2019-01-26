#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll         pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int t , n ;



int main()
{
    fastRead;
    cin>>t;
    while( t-- ) {
        int n ;
        string str;
        cin>>n>>str;
        string s1 = "";
        string s2 = "";
        s1 += str[0];
        for(int i = 1 ; i < n ; i++ ) s2 += str[i];

        if( n ==2 ) {
            int num1 = s1[0] - '0';
            int num2 = s2[0] - '0';
            if( num1 >= num2 ) {
                cout<<"NO\n";
                continue;
            }
        }
        cout<<"YES\n";
        cout<<"2\n";
        cout<<s1<<" "<<s2<<'\n';

    }
    return 0;
}
