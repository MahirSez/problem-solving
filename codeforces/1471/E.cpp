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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int cnt = 0;


int ask(int id) {
    cnt++;
    assert(cnt <= 1000);

    cout<<"? "<<id<<endl;
    int ret;
    cin>>ret;
    return ret;
}

int main()  {
    int n, k;
    
    cin>>n>>k;

    int id, val;

    while(1) {
        id = rng()%n+1;

        val = ask(id);
        if(val != k) break;
    }

    while(1) {

        if(val > k) {
            id --;
            if(id == 0) id = n;
        }
        else if(val < k) {
            id++;
            if(id == n) id = 1;
        }
        else {
            cout<<"! "<<id<<endl;
            return 0;
        }

        val = ask(id);


    }



    

    return 0;
}