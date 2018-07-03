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
int zer , one  , x;
int main()
{
    cin>>zer>>one>>x;
    string str = "";
    int prev;
    if( zer > one) {
        str += '0';
        zer--;
        prev = 0;
    }
    else {
        str += '1';
        one--;
        prev = 1;
    }
    while( x-- ) {
        if( prev == 1) {
            str += '0';
            zer--;
        }
        else {
            str += '1';
            one--;
        }
        prev ^=1;
    }
//    cout<<str<<" "<<one<<" "<<zer<<endl;
//    return 0;
    for(int i =0 ; i < str.size() ; i++) {
        cout<<str[i];
        if( str[i] == '0') {
            if( zer > 0) while( zer--) cout<<'0';
        }
        else {
            if( one > 0) while(one--) cout<<'1';
        }
    }
    cout<<endl;
    return 0;
}
