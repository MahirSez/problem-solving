#include <bits/stdc++.h>
#define ll          long long int
#define PI          acos(-1)
#define read        freopen("in.txt","r",stdin)
#define uu          first
#define vv          second
#define write       freopen("out.txt","w",stdout)
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define EPS         1e-8
#define MAX         2750135
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n  , mark[MAX] , rec[MAX] ,ans[MAX];
vector<int>prm , ps , nps , str;

void seive() {
    
    for(int i = 2 ; i*i < MAX; i++ ) {
        if( mark[i] ) continue;
        for(int j = i*i ; j < MAX; j+=i)  {
            mark[j] = 1;
        }
    }
    prm.push_back(-1);
    
    for(int i =2 ; i < MAX; i++ ) {
        if( mark[i] ==0 ) prm.push_back(i);
    }
}

int div(int num) {
    
    for(int i =2 ; i < num ; i++ ) {
        if( num %i ==0 ) {
            return num/i; 
        }
    }
}


int main()
{
    fastRead;
    seive();
    cin>>n;
    for(int i = 0 ; i < 2*n; i++ ) {
        int tmp;
        cin>>tmp;
        rec[tmp]++;
        if( mark[tmp] ==0 )  ps.push_back(tmp);
        else nps.push_back(tmp);
    }
    
    sort(nps.rbegin() , nps.rend());
    sort(ps.begin() , ps.end());
    
    for(auto x : nps ) {
        
        if( rec[x] ==0 ) continue;
        rec[x]--;
        int get = div(x);
        assert(rec[get] > 0 );
        rec[get]--;
        str.push_back(x);
    }
    
    for(auto x : ps ) {
        
        if( rec[x] ==0 ) continue;
        rec[x]--;
        int get = prm[x];
        assert(rec[get] > 0 );
        rec[get]--;
        str.push_back(x);
    }
    
    for(auto x : str) {
        cout<<x<<" ";
    }
    cout<<'\n';
    return 0;
}