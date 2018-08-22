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
int n  , prm[MAX];
vector<int>v ,ans;
vector<pii>in;
void seive() {
    for(int i=2 ; i * i < MAX ; i++ ) {
        if( prm[i]) continue;
        for(int j = i*i ; j < MAX ; j+=i) {
            prm[j] = 1 ;
        }
    }
    for(int i =2 ; i < MAX; i++ ) {
        if( prm[i] == 0 ) {
            v.push_back(i);
        }
    }
}

void solve(int tmp) {
    for(int i =0 ; i < v.size() ; i++ ) {
        bool ok = false;
        while( tmp%v[i] ==0 ) {
            tmp /= v[i];
            ok = true;
        }
        if( ok ) ans.push_back(v[i]);
    }
    if( tmp != 1) ans.push_back(tmp);
}

int main()
{
    fastRead;
    seive();
    cin>>n;
    for(int i =0 ; i < n ; i++ ) {
        int a , b;
        cin>>a>>b;
        in.push_back({a,b});
    }
    solve(in[0].uu);
    solve(in[0].vv);
    sort( ans.begin() , ans.end());
    ans.erase( unique( ans.begin() , ans.end()) , ans.end() ) ;

    for(int i = 0 ; i < ans.size() ; i++ ) {
        bool ok = true;
        for(int j = 0 ; j < n  ; j++ ) {
            if( in[j].uu % ans[i] && in[j].vv % ans[i]) {
                ok = false;
                break;
            }
        }
        if( ok ) {
            cout<<ans[i]<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
