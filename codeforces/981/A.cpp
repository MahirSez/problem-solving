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
string str;
int cnt , l , r , ans;

bool isPal(int l , int r) {

    for(int i = l , j = r; i<=j; i++ , j--) {
        if( str[i]!=str[j]) return false;
    }
    return true;
}

int main()
{
    cin>>str;
    for(int i =0 ; i < str.size() ; i++ ) {
        for(int j = i+1 ; j < str.size() ; j++ ) {

            if( !isPal(i,j) ) {
                ans = max( ans , j-i+1);
            }
        }
    }
    cout<<ans<<endl;
}
