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
int n , m ;
string tgt;

struct node {
    int endMark;
    node *next[3];
    node() {
        memset(next , 0 , sizeof next);
        endMark = 0;
    }
} *root = new node();

void Insert(int id , node* v) {

    if(id == tgt.size() ) {
        v->endMark  = 1;
        return;
    }
    int col = tgt[id] - 'a';

    if(v->next[col] == 0 ) {
        v->next[col] = new node();
    }
    Insert(id+1 , v->next[col]);
}

bool Search(int id , int taken , node* v) {

    if( taken > 1) return false;
    if(id == tgt.size() ) {
        return (taken == 1 && v->endMark ==1);
    }

    int col = tgt[id] - 'a';

    bool ret = false;
    for(int i = 0; i < 3 ; i++ ) {

        if( v->next[i] == NULL) continue;
        else if( col == i) ret |= Search(id+1 , taken , v->next[i]);
        else ret |= Search(id+1 , taken+1 , v->next[i]);
    }
    return ret;
}

void del(node* v) {
    for(int i =0 ; i < 3; i++ ) {
        if( v->next[i] ) del(v->next[i]);
    }
    delete v;
}

int main()
{
    fastRead;
    cin>>n>>m;
    for(int i =0  ; i < n ; i++ ) {
        cin>>tgt;
        Insert( 0 , root);
    }

    for(int i =0 ; i < m ; i++) {
        cin>>tgt;
        if( Search(0 , 0 , root) ) {
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
    del(root);
    return 0;
}
