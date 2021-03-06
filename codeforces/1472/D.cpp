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

int main()  {
    fastio;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<ll>vec(n);
        for(int i =0; i< n; i++ ) cin>>vec[i];
        sort(vec.rbegin() , vec.rend());
        ll sum1= 0, sum2= 0;
        for(int i =0; i <n ; i++ ) {
            if(i%2 == 0 && vec[i]%2 ==0) sum1 += vec[i];
            if(i%2  && vec[i]%2 ) sum2 += vec[i];
        }

        if(sum1 == sum2) cout<<"Tie\n";
        else if(sum1 > sum2) cout<<"Alice\n";
        else cout<<"Bob\n";
    }
    return 0;

}