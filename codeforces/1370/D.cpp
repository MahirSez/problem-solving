#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         2e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e5 + 5;

/*
4 3
4 3 2 1
*/

int getLenOdd(vector<pii>&vec, int till, int k) {
    
    int n = vec.size();
    
    vector<int>rec(n+1);
    
    for(auto x : vec) {
        if(x.uu <= till) rec[x.vv] = 1;
    }
    
    int cnt = 0, ans = 0;
    
    
    int tmp ;
    if(k%2) tmp = n;
    else tmp = n-1;
    
    for(int i =0 ; i <= n ; i++ ) {
        
        if(i == tmp) {
            ans += (cnt+1)/2;
            break;
        }
        if(rec[i] == 0) {
            ans += (cnt+1)/2;
            cnt = 0;
        }
        else cnt++;
    }
    return ans;
}

int getLenEv(vector<pii>&vec, int till, int k) {
    
    int n = vec.size();
    
    vector<int>rec(n+1);
    
    for(auto x : vec) {
        if(x.uu <= till) rec[x.vv] = 1;
    }
    
    int tmp;
    if(k%2 == 0 ) tmp = n;
    else tmp = n-1;
    
    int cnt = 0, ans = 0;

    for(int i =1 ; i <= n ; i++ ) {
        
        if(i == tmp) {
            ans += (cnt+1)/2;
            break;
        }
        if(rec[i] == 0) {
            ans += (cnt+1)/2;
            cnt = 0;
        }
        else cnt++;
    }
    return ans;
}


int solve(vector<pii>&vec, int k, int odd) {
    
    int n = vec.size();
    
    
    int tgt = (k+1)/2;
    if(odd==0) tgt = k/2;
    
    int lo = 0, hi = n-1, ret = INF;
    
    while(lo<=hi) {
        
        int mid = (lo+hi)/2;
        
        int len = -1;
        if(odd) len = getLenOdd(vec, vec[mid].uu,k);
        else len = getLenEv(vec, vec[mid].uu, k);
        
//        cout<<vec[mid].uu<<" "<<len<<'\n';
        if(len >= tgt) {
            ret = min(ret , vec[mid].uu );
            hi = mid -1;
        }
        else lo = mid + 1;
    }
    return ret;
    
}

int main()
{
    fastRead;
    int n, k;
    cin>>n>>k;
    vector<pii>vec(n);
    for(int i =0 ; i < n ; i++ ) {
        cin>>vec[i].uu;
        vec[i].vv = i;
    }
    sort(vec.begin(), vec.end());
    
    int ret1 = solve(vec, k, 1);
    
//    cout<<ret1<<'\n';
    int ret2 = solve(vec, k, 0);
//    cout<<ret2<<'\n';
    cout<<min(ret1, ret2)<<'\n';
    return 0;
}