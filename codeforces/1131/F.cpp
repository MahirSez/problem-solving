#include<bits/stdc++.h>
#define MAX 1000006
using namespace std;
int  lPar[MAX] , rPar[MAX] , l[MAX];
int n , mark[MAX];


int getR(int x) {

    if( rPar[x] == x) return x;
    return rPar[x] = getR(rPar[x]);
}

int getL(int x) {
    if( lPar[x] == x) return x;
    return lPar[x] = getL(lPar[x]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(l , -1 , sizeof l);
    cin>>n;
    for(int i =1 ; i <= n ; i++ ) {
        rPar[i] = i;
        lPar[i] = i;
    }

    for(int i =1 ; i < n ; i++ ) {
        int u , v;
        cin>>u>>v;


        int RU = getR(u);
        int LV = getL(v);

        l[RU] = LV;
        rPar[RU] = getR(v);
        lPar[LV] = getL(u);
    }
    

    for(int i =1 ; i <= n ; i++ ) {
        if( l[i] ==-1) continue;
        mark[l[i]] = 1;
    }
    
    int st = 0;
    for(int i =1 ; i <= n ; i++ ) {
        if( mark[i] == 0 ) st = i;
    }

    while( st != -1) {
        cout<<st<<" ";
        st = l[st];
    }
    cout<<endl;
    return 0;
}