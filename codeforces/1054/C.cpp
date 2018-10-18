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
int  n , l[MAX] , r[MAX] ,ara[MAX];
int main()
{
    fastRead;
    cin>>n;
    for(int  i=0  ;i < n ; i++ ) cin>>l[i];
    for(int  i=0  ;i < n ; i++ ) cin>>r[i];
    for(int i =0 ; i < n ; i++ ) {
        ara[i] = n- l[i] - r[i];
    }
    for(int i =0 ; i < n ; i++ ) {
        int cnt = 0;
        for(int j = 0 ; j < i ; j++ ) {
            if( ara[j] > ara[i]) cnt++;
        }
        int ccnt = 0;
        for(int j = i+1 ; j < n ;j++ ) {
            if( ara[j] > ara[i]) ccnt++;
        }
        if( cnt !=l[i] || ccnt != r[i] ) {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    for(int i = 0 ; i < n ; i++ ) {
        cout<<ara[i]<<" ";
    }
    cout<<endl;
}
