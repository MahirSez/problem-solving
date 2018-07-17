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
int n , till;
ll tot;
vector<int>v;
int turn(int tgt) {
    int cnt = 0;
    while( tgt ) {
        tgt>>=1 ;
        cnt++;
    }

    return ((1<<cnt) - 1);
}

int main()
{
    cin>>n;
    till = n;
    while( n >= 0 ) {
        int tgt = turn(n);
        int tmp = tgt ^ n;

        for(int i = tmp ;  i<= till ; i++ , n--) {
            v.push_back(i);
            tot += (i ^ n);
        }
        till = tmp - 1;
    }
    reverse(v.begin() , v.end());
    cout<<tot<<endl;
    for(int i =0 ; i < v.size() ; i++ ) {
        printf("%d ",v[i]);
    }
    cout<<endl;
    return  0;
}
