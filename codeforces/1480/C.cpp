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


int cnt = 0;
int ask(int id)  {
    if(id == 0 || id == n+1)  return INF;
    cnt++;
    assert(cnt <= 100);
    cout<<"? "<<id<<endl;
    int ret;
    cin>>ret;
    return ret;
}

int main()  {
    // fastio;
    
    cin>>n;
    

    int lo = 0, hi = n+1;
    while(hi - lo > 2) {
        
        int mid1 = (hi+lo)/2;
        int mid2 = mid1 + 1;
        // cout<<lo<<" "<<hi<<" -- "<<mid1<<" "<<mid2<<endl;
        int val1 = ask(mid1);
        int val2 = ask(mid2);
        if(val1 < val2) hi = mid2;
        else lo = mid1;
    }


    cout<<"! "<<lo + 1<<endl;
    return 0;


    // assert(0);

}