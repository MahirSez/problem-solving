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
int main()
{
    cin>>str;
    int n = str.size();
    int now = 0 ;
    int mx = 0;
    for(int i =0 ; i < str.size() ;  ) {

        int col = (str[i]=='b');
        int j =0 ;
        int cnt = 0;
        for(j = i , cnt = 0;  cnt < str.size() ; j++) {
            j = j % (n);
            if( col ==1 && str[j]!= 'b') break;
            if( col ==0 && str[j]!= 'w') break;
            col ^= 1;
            cnt++;
        }
        cnt= min( cnt , n);
        mx = max(mx , cnt);
        if( j <= i || cnt==n) break;
        else i = j;
    }
    cout<<mx<<endl;
    return 0;
}
