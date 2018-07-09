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
int ara[MAX];
string str;
int main()
{
    cin>>str;
    for(int i= 0 ; i < str.size() ; i++ ) {
        int tmp = str[i] - '0';
        ara[i] = tmp%3;
    }
    int n = str.size();
    int one = 0 , two = 0 ,cnt = 0;
    for(int  i=0 ; i < n ; i++ ) {
        if( ara[i] == 0) {
            cnt++;
            one = 0;
            two = 0;
        }
        else if( ara[i] == 1) one++;
        else if( ara[i] ==2 ) two++;

        if( one>= 3 || two >=3) {
            one = 0;
            two = 0;
            cnt++;
        }
        else if( one >=1 && two >= 1) {
            one = 0;
            two = 0;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
