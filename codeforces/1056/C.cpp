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
int n , m ,  taken[MAX] , bro[MAX] , cnt , rec[MAX];
pii ara[MAX];
vector<pii>v;

void play1()
{
    for(int i =0 ; i < v.size() ; i++ ){

        if( taken[v[i].uu] ) continue;
        if( cnt ==0 ) return;

        cout<<v[i].uu<<endl;
        taken[v[i].uu] = 1;

        cnt--;
        if( cnt ==0 ) return;

        int tmp;
        cin>>tmp;
        if( tmp == -1) return ;
        taken[tmp] = 1;
        cnt--;
        if( cnt ==0 ) return;
    }
    if( cnt==0 ) return;

    for(int i = 1 ; i <=2*n ; i++ ) {
        int tmp  = ara[i].vv;

        if( taken[tmp] == 0) {
            cout<<tmp<<endl;
            taken[tmp] = 1;
            cnt--;
            if( cnt==0) return;
            cin>>tmp;
            if( tmp == -1) return ;
            taken[tmp] = 1;
            cnt--;
            if( cnt==0) return;
        }
    }
}
void play2() {

    while( cnt > 0) {
        int tmp;
        cin>>tmp;
        cnt--;
        if( cnt==0) return;
        taken[tmp] =1;
        if( bro[tmp] ==0) {
            play1();
            return;
        }
        else {
            cout<<bro[tmp]<<endl;
            taken[bro[tmp]] = 1;
            cnt--;
            if( cnt==0) return;
        }
    }
}

bool comp(pii p1 , pii p2) {

    if( rec[p1.uu] == rec[p2.uu]) return rec[p1.vv] < rec[p2.vv];
    return rec[p1.uu] > rec[p2.uu];

}

int main()
{
    fastRead;
    cin>>n>>m;
    cnt = 2*n;
    for(int i =1 ; i<= 2*n ; i++ ) {
        int tmp;
        cin>>tmp;
        ara[i].uu = tmp;
        ara[i].vv = i;
        rec[i] = tmp;
    }
    sort(ara +1, ara + 2*n+1);
    reverse(ara +1, ara + 2*n+1);

    for(int i =1 ; i<= m ; i++ ) {
        int f , s;
        cin>>f>>s;
        bro[f] = s;
        bro[s] = f;
        if( rec[f] < rec[s] ) swap(f,s);
        v.push_back({f,s});
    }
    sort(v.begin() , v.end() , comp);

//    for(int i = 0 ; i < v.size() ; i++ ) {
//        cout<<rec[v[i].uu]<<" "<<rec[v[i].vv]<<endl;
//    }

    int flg;
    cin>>flg;

    if( flg == 1) {

        play1();
    }
    else {
        play2();
    }
    return 0;
}

