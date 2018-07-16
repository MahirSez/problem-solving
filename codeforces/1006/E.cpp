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
int n ,q , tim;
vector<int>edg[MAX];
vector<int>str;
int fin[MAX] , id[MAX];

void dfs(int node) {
    str.push_back(node);
    id[node] = str.size()-1;

    tim++;
    for(int i =0 ; i < edg[node].size() ;i++ ) {
        int x = edg[node][i];
        dfs(x);
    }
    fin[node] = ++tim;
}

int main()
{
    fastRead;
    cin>>n>>q;
    for(int i = 2 ; i<= n ; i++ ){
        int tmp;
        cin>>tmp;
        edg[tmp].push_back(i);
    }
    for(int i= 1 ; i<= n ; i++ ) {
        sort( edg[i].begin() , edg[i].end());
    }

    dfs(1);
//    reverse(str.begin() , str.end() ) ;
//    for(int i =0 ; i <str.size() ; i++ ) {
//        cout<<str[i]<<" "<<fin[str[i]]<<endl;
//    }
//    cout<<"wtf"<<endl;

    while( q-- ) {
        int tmp , k;
        cin>>tmp>> k;
        k--;
        int tgtID = id[tmp];
        if( tgtID + k >= n || fin[ str[tgtID+k] ] > fin[tmp] ) {
            printf("-1\n");
        }
        else printf("%d\n",str[tgtID+k]);
    }
    return 0;
}
