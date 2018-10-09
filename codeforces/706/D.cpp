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
    node* next[2];
    int child;
    node() {
        child = 0;
        next[1] = next[0] = 0;
    }
} *root;


void Insert(int tmp) {

    node* curr = root;
    root->child +=1;
    for(int i = 31 ; i>=0 ; i--) {
        bool val = (tmp & (1<<i) );
        if( curr-> next[val] == 0) {
            curr->next[val] = new node();
        }

        curr = curr->next[val];

        curr->child += 1;
//        if( i < 5) cout<<i<<" "<<val<<" "<<curr->child<<endl;
    }
//    cout<<endl;
    curr = root;
    for(int i = 31 ;i>=0 ; i--) {
        bool val = (tmp & (1<<i) );

        curr = curr->next[val];
//        if( i < 5) cout<<i<<" "<<val<<" "<<curr->child<<endl;
    }
}

void Delete(int tmp) {
    node* curr = root;
    root->child -=1;
    for(int i = 31 ; i>=0 ; i-- ) {
        bool val = (tmp &(1<<i));
        curr = curr->next[val];
        curr->child -=1;
    }
}

int Query(int tmp) {
    node* curr = root;
    int ans = 0;
    for(int i = 31 ;i >= 0 ; i--) {
        ans <<= 1;
        int bit = !(tmp &(1<<i));
        if(curr->next[bit]==0 || curr->next[bit]->child==0 )bit ^=1;
        curr = curr->next[bit];
        ans |= bit;
//        if( i < 5) cout<<i<<" "<<bit<<" "<<curr->child<<endl;
    }
    return (ans^tmp);
}

int q ;
int main()
{
    fastRead;
    root = new node();
    Insert(0);
    cin>>q;
    while( q-- ) {
        string s, s1;
        int tmp;
        cin>>s>>tmp;
        if( s== "+") Insert(tmp);
        else if( s=="-") Delete(tmp);
        else cout<<Query(tmp)<<'\n';
    }
    cout<<endl;
    return 0;
}
