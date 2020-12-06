#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define tp          tuple<int,int,int>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;
int n;
int xors[N], rec[N], ara[N];

int askxor(int id1 , int id2) {
    cout<<"XOR "<<id1<<" "<<id2<<endl;
    int ret;
    cin>>ret;
    return ret;
}

int askand(int id1 , int id2) {
    cout<<"AND "<<id1<<" "<<id2<<endl;
    int ret;
    cin>>ret;
    return ret;
}

void solvedup(int id1, int id2) {
    int andval = askand(id1, id2);
    ara[1] = andval ^ xors[id1];
}

void solveunique() {

    int id1 = rec[n-1], id2 = 2;
    if(id1 == id2) id2++;

    int andval1 = askand(id1, id2);

    int ans = 0;

    for(int i = 0 ; i < n ; i++ ) {
        if( (xors[id1] & (1<<i)) && (xors[id2] & (1<<i)) && (andval1 & (1<<i)) ) {
            ans |= (1<<i);
        }
    }

    int id3 = rec[ (n-1) ^ xors[id2] ];

    int andval2 = askand(id1, id3);

    for(int i = 0 ; i < n ; i++ ) {
        if( (xors[id1] & (1<<i)) && (xors[id3] & (1<<i)) && (andval2 & (1<<i)) ) {
            ans |= (1<<i);
        }
    }


    ara[1] = ans ^ xors[id1];
}

int main() {
    cin>>n;

    for(int i =2 ; i <= n ; i++ ) xors[i] = askxor(1, i);

    int dupfound = 0 , dup1, dup2 ;

    for(int i = 1 ; i <=n ; i++ ) {
        if(rec[xors[i]] == 0) rec[xors[i]] = i;
        else if(dupfound ==0) {
            dup1 = i;
            dup2 = rec[xors[i]];
            dupfound = 1;
        }
    }

    // for(int i =0 ; i <n ; i++ ) {
    //     cout<<i<<" "<<rec[i]<<'\n';
    // }

    if(dupfound) solvedup(dup1, dup2);
    else solveunique();


    for(int i =2 ; i <=n ; i++ ) {
        ara[i] = ara[1] ^ xors[i];
    }

    cout<<"! ";
    for(int i= 1 ; i <=n ; i++ ) cout<<ara[i]<<" ";
    cout<<endl;
    return 0;



}