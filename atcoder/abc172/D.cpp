#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e7 + 6;

ll rec[MAX];

void seive() {
    
    for(int i =1 ; i < MAX ; i++ ) rec[i] = 1;
    
    for(int i = 2 ; i < MAX ; i++ ) {
        if(rec[i] != 1) continue;
        for(int j = i ; j < MAX ; j += i ) {
            
            int tmp = j;
            int cnt = 0;
            
            while(tmp % i == 0) cnt++, tmp /= i;
            
            rec[j] *= 1LL*(cnt+1);
        }
    }
    
//    for(int i =1 ; i < 10 ; i++) cout<<rec[i]<<" ";
//    cout<<'\n';
}
int main()
{
    fastRead;
    seive();
    
    for(int i =1 ; i < MAX ; i++ ) {
        rec[i] = rec[i-1] + i *(rec[i]);
    }
    int n;
    cin>>n;
    cout<<rec[n]<<'\n';
    return 0;
}