#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pip 		pair<int,pii>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
string str;
int n;
int main()
{
    fastRead;
    cin>>n>>str;
    int cnt= 0;

    for(int i =0 ; i< n ; i++) {
        cnt+= (str[i] =='8');
    }
    int tmp = (n -11)/2;

    if( tmp >= cnt) {
        cout<<"NO"<<endl;
        return 0;
    }
    int tmp1 = tmp;

    for(int i =0 ; i < n ; i++) {

        if( tmp>0 && str[i]=='8') {
            str[i] = '*';
            tmp--;
        }
    }


    for(int i =0 ;i < n ; i++) {
        if(tmp1 > 0 && str[i] == '8') {
            cout<<"YES"<<endl;
            return 0;
        }
        if( tmp1>0 && str[i] !='*' ) {
            str[i] = '*';
            tmp1--;
        }
    }

    for(int i =0 ; i < n ; i ++) {
        if( str[i] != '*' ) {
            if(str[i] == '8') {
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
            return 0;
        }
    }

    return 0;
}
