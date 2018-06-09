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
vector<int>v;
int ara[200],fact[200] ,n,dp[101][1<<18] , nxt[101][1<<18];

void genPrm() {
    for(int i =2 ; i<= 65 ;i++ ) {
        bool ok = true;
        for( int j = 2 ; j *j <= i; j++) {
            if( i%j==0) ok = false;
        }
        if( ok ) v.push_back(i);
    }
//    cout<<v.size()<<endl;
//    for(int i = 0 ; i < v.size() ; i++ ) cout<<v[i]<<" ";
//    cout<<endl;
}

void genMask() {
    for(int i = 1 ; i <= 60 ; i++ ) {
        for(int j =0 ; v[j] <= i;j++ ) {
            if( i%v[j] == 0 ) {
                fact[i] |= (1<<j);
            }
        }
    }
}

int  solve(int id ,int mask) {
    if( id == n) return 0;
    int &ret = dp[id][mask];
    if( ret != -1 ) return ret;
    ret = INF;
    for(int i = 1 ; i<= 60 ; i++ ) {
        if( mask & fact[i] ) continue;
        int tmp = abs(ara[id] - i) + solve(id+1 , mask | fact[i]);
        if( tmp < ret ) {
            ret = tmp;
            nxt[id][mask] = i;
        }
    }
    return ret;
}

void print(int id ,int mask) {
    if( id == n) return ;
    int tmp = nxt[id][mask];
    cout<<tmp<<" ";
    print(id + 1 , mask | fact[tmp]);
}

int main()
{
    fastRead;
    genPrm();
    genMask();
    cin>>n;
    for(int i =0 ; i < n ;i++ ) cin>>ara[i];
    memset(dp , -1 , sizeof dp);
    solve(0,0);
    print(0,0);
    cout<<endl;
    return 0;
}
