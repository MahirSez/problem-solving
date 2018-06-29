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
string str;
int nxt[27];
int strt[27];
int main()
{
    cin>>n;
    memset( strt , 0 , sizeof strt);
    for(int i =0 ; i <n ; i++  ) {
        cin>>str;

        if( strt[str[0]-'a'+1] == 0 ) {
            strt[str[0]-'a'+1] = 1;
        }
        for(int i=1 ; i< str.size() ; i++ ) {
            nxt[str[i-1]-'a'+1] = str[i]-'a'+1;
            strt[str[i]-'a'+1] = -1;
        }
    }
//    for(int i =1 ; i<= 26 ; i ++) cout<<strt[i]<<" ";
//    cout<<endl;
//    for(int i =1 ; i<= 26 ; i ++) cout<<nxt[i]<<" ";
//    cout<<endl;
    for(int i =1 ;i<= 26 ; i++) {
        if(strt[i]==1) {
            int tmp = i;
            cout<<(char)(tmp-1+'a');
            while( nxt[tmp] ) {
                tmp = nxt[tmp];
                cout<<(char)(tmp-1+'a');
            }
        }
    }
    cout<<endl;
    return 0;
}
