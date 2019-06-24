#include<bits/stdc++.h>
#define uu first
#define vv second
using namespace std;

typedef pair<int,int> pii;

const int N = 1e5 + 5;

int n , ara[N];
vector<pii>v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i =0 ; i < n ; i++ ) {
        int tmp;
        cin>>tmp;
        if( tmp >=0 ) tmp = (-tmp - 1);
        v.push_back({tmp,i});
    }
    
    sort(v.rbegin() , v.rend( ));
    
    for(int i =0 ; i +1< n ; i+=2 ) {
        
        ara[v[i].vv] = v[i].uu;
        ara[v[i+1].vv] = v[i+1].uu;
    }
    if( n & 1) {
        ara[v[n-1].vv] = -v[n-1].uu - 1;
    }
    
    for(int i =0 ; i < n ; i++ ) {
        cout<<ara[i]<<" ";
    }
    cout<<'\n';
    return 0;
}
