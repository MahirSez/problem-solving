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
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
int n , m , cl[MAX] ,taken[MAX];
set<int>s[MAX];
int main()
{
    fastRead;
    cin>>n>>m;
    for(int i= 1 ; i <= n ;i++  ) {
        cin>>cl[i];
        taken[cl[i]] = 1;
    }
    for(int i =0  ; i < m ;i++ ) {
        int a, b;
        cin>>a>>b;
        if( cl[a] == cl[b]) continue;
        s[cl[a]].insert(cl[b]);
        s[cl[b]].insert(cl[a]);
    }
    int mx = -1 , id = -1;

    for(int  i= 1; i < MAX ; i++ ) {
        int sz = s[i].size();
        if( taken[i] && sz > mx) {
            id = i;
            mx = sz;
        }
    }
    cout<<id<<endl;
    return 0;
}
