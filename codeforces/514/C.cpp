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
int trie[MAX][3] , n , m ,root , sz;
int en[MAX][3];
string tgt;



void Insert(string str) {
    int len = str.size() , v = root ;
    for(int i =0 ; i < len ; i++ ) {

        int id = str[i] - 'a';

        if( trie[v][id] == 0 )  trie[v][id] = ++sz;
        if( i == len -1 ) en[v][id]  =1 ;
        v = trie[v][id];
    }
}


bool Search(int id , int taken ,int rt, bool done) {

    if( taken > 1 ) return false;
    if( id == tgt.size() ) {
        return ( taken == 1 && done );
    }
    bool ret = false;
    int col = tgt[id] - 'a';
    if( trie[rt][col] ) {
        ret = Search(id+1 , taken , trie[rt][col] , en[rt][col]);
    }
    for(int i =0 ; i < 3 ; i++ ) {

        if( i == col ) continue;
        if( trie[rt][i] == 0 ) continue;
        ret |= Search(id+1 , taken+1 , trie[rt][i] , en[rt][i]);
    }
    return ret;

}

int main()
{
    fastRead;
    cin>>n>>m;
    for(int i =0  ; i < n ; i++ ) {
        string str;
        cin>>str;
        Insert(str);
    }

    for(int i =0 ; i < m ; i++) {
        cin>>tgt;
        if( Search(0 , 0 , 0 , 0) ) {
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
    return 0;
}
