#include <bits/stdc++.h>
#define ll			long long int
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
int n , m;
string str[100];
int main()
{
    cin>>n>>m;
    for(int  i= 0 ; i < n; i++ ) {
        cin>>str[i];
    }
    bool flg = true;
    for(int  i =0 ; i < n;i++ ) {

        for(int j = i+1; j < n;j++) {

            string s1 = str[i];
            string s2 = str[j];

            if( s1 == s2 ) continue;

            for(int k = 0; k < m ;k++) {

                if( s1[k]=='#' && s2[k] == '#')
                    flg = false;
            }
        }
    }

    if(flg) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
