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
int n , ara[MAX] , p[MAX];
vector<int>v;

struct node {
    node *next[2];
    int cnt ;
    node() {
        next[0] = NULL;
        next[1] = NULL;
        cnt = 0;
    }
} *root;


void convert(int tmp) {
    v.clear();
    while(tmp) {
        v.push_back(tmp&1);
        tmp>>=1;
    }
    while( v.size() < 31 ) v.push_back(0);
}

void Insert() {

    node *curr = root;
    for(int i =v.size()-1 ; i >=0 ; i-- ) {
        if( curr->next[v[i]] == NULL) {
            curr->next[v[i]] = new node();
        }
        curr = curr->next[v[i]];
        curr->cnt++;
    }
}

int Search() {

    node *curr = root;
    int ans = 0;

    for(int i =v.size()-1 ; i >=0 ; i-- ) {
        if(curr->next[v[i]] && curr->next[v[i]]->cnt ) {
            curr = curr->next[v[i]];
            curr->cnt--;
            ans |= (v[i]<<i);
        }
        else {
            curr = curr->next[v[i]^1];
            curr->cnt--;
            ans |= ((v[i]^1)<<i);
        }
    }
    return ans;
}
int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) cin>>ara[i];
    root = new node();
    for(int i =0 ; i < n ; i ++ ) {
        int tmp;
        cin>>tmp;
        convert(tmp);
        Insert();
    }
    for(int i =0 ; i < n ; i++ ) {
        convert(ara[i]);
        cout<<(Search() ^ ara[i])<<" ";
    }
    cout<<endl;
    return 0;
}
