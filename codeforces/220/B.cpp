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
struct node {
    int  l , r , id;
} q[MAX];
int n , m , ara[MAX] , rt ,cnt , ans[MAX] , mp[MAX];
bool comp(node n1 , node n2) {
    if( n1.l/rt == n2.l/rt ) return n1.r < n2.r;
    return (n1.l/rt < n2.l/rt);
}

void Add(int pos) {
    if( ara[pos] > n) return;
    int tmp = ara[pos];
    if( mp[tmp] == tmp) cnt--;
    mp[tmp]++;
    if( mp[tmp] == tmp) cnt++;
}

void Remove(int pos) {
    if( ara[pos] > n) return;
    int tmp = ara[pos];
    if( mp[tmp] == tmp) cnt--;
    mp[tmp]--;
    if( mp[tmp] == tmp) cnt++;
}

void solve() {
    int nowL = 0, nowR = 0;
    Add(0);
    for(int i = 0 ;i < m ; i++ ) {
        int L= q[i].l , R = q[i].r;

        while( nowL < L) {
            Remove(nowL);
            nowL++;
        }
        while( nowL > L) {
            nowL--;
            Add(nowL);
        }
        while( nowR < R) {
            nowR++;
            Add(nowR);
        }
        while( nowR> R) {
            Remove(nowR);
            nowR--;
        }
        ans[q[i].id] = cnt;
    }
}



int main()
{
    fastRead;
    cin>>n>>m;
    rt = sqrt(n);
    for(int i =0 ; i < n ;i++ ) cin>>ara[i];
    for(int i= 0 ; i < m ;i++ ) {
        cin>>q[i].l>>q[i].r;
        q[i].l--;
        q[i].r--;
        q[i].id = i;
    }
    sort(q , q + m , comp);
    solve();
    for(int i = 0 ; i < m ; i++ ) {
        cout<<ans[i]<<'\n';
    }
    cout<<endl;
    return 0;
}
