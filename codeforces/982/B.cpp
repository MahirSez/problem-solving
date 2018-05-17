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
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n,  in =1;
stack<int>ex;
pii ara[MAX];
string str;
int main()
{
    fastRead;
    cin>>n;
    for(int i =1 ; i<= n ; i++ ) {
        int tmp;
        cin>>tmp;
        ara[i].uu = tmp;
        ara[i].vv = i;
    }
    sort(ara +1, ara + n + 1);
    cin>>str;
    for(int  i= 0 ; i < 2*n ; i++ ) {

        if( str[i] == '0') {
            cout<<ara[in].vv<<" ";
            ex.push(ara[in].vv);
            in++;
        }
        else {
            cout<<ex.top()<<" ";
            ex.pop();
        }
    }
    cout<<endl;
    return 0;
}
