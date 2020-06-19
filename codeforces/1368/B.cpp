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
int main()
{
    fastRead;
    ll k;
    cin>>k;
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    for(int i =0 ; i < 10 ; i++ ) pq.push(1);
    ll now = 1;
    
    string cf = "codeforces";
    
    while(now < k) {
        ll top = pq.top() ;
        pq.pop();
        now /= top;
        top++;
        now *= top;
        pq.push(top);
    }
    
    for(int i =0 ; i < 10; i++) {
        int tmp = pq.top();
        pq.pop();
        while(tmp--) cout<<cf[i];
    }
    cout<<'\n';
    return 0;
    
}