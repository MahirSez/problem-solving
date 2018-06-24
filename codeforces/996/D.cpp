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
int n , ara[200];
int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i <2*n ; i++ ) cin>>ara[i];
    int cnt = 0;
    for(int i = 0 ; i < 2*n -1; i++ )  {
        if( ara[i] == ara[i+1]) continue;
        int tgt = ara[i];
        for(int j = i+1 ;j < 2*n ; j++ ) {
            if( ara[j] == tgt) {

                for(int k = j ; k-1>i ; k--) {
                    swap(ara[k] , ara[k-1]);
                    cnt++;
                }
            }
        }
    }
    cout<<cnt<<endl;
}
