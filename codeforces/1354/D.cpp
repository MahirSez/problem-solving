#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;

int bit[MAX];
int n , q;
int query(int id) {
    int sum=0;
    while(id>0) {
        sum += bit[id];
        id -= id & (-id);
    }
    return sum;
}
void update(int id, int x){ 
    while(id<=n) {
        bit[id]+=x;
        id += id & (-id);
    }
}

void Erase(int key) {
    
    int lo = 1 , hi = n , ret = -1;
    while(lo <=hi) {
        int mid = (lo+hi)/2;
        int tmp = query(mid);
        if(tmp >= key) {
            ret = mid;
            hi = mid-1;
        }
        else lo = mid + 1;
    }
//    cout<<key<<"-> "<<ret<<'\n';
    update(ret , -1);
}

int main()
{
    fastRead;
    
    cin>>n>>q;
    for(int i =0 ; i < n; i++ ) {
        int tmp;
        cin>>tmp;
        update(tmp , 1);
    }
    for(int i =0 ; i < q ; i++ ) {
        int tmp;
        cin>>tmp;
        if(tmp > 0) update(tmp , 1);
        else Erase(abs(tmp));
    }
    for(int i =1 ; i <=n ; i++ ) {
        if(query(i)) {
            cout<<i<<'\n';
            return 0;
        }
    }
    
    cout<<0<<'\n';
    return 0;
    
}