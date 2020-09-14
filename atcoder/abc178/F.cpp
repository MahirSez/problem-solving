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
vector<int>rec[N];


int main()  {
    fastio;
    int n;
    cin>>n;
    vector<int>vec1(n) , vec2(n) , ans, rec;
    for(int i =0 ; i < n ; i++ ) cin>>vec1[i];
    for(int j =0 ;  j< n ; j++ ) cin>>vec2[j];
    ans = vec2;

    reverse(vec2.begin() , vec2.end());
    int l  = n , r = -1;
    for(int i = 0 ; i < n ; i++ ) {
        if(vec1[i] == vec2[i]) {
            l = min(l, i);
            r = max(r ,i);
            rec.push_back(i);
        }
    }

    for(int i =0 ; i < n && rec.size() ; i++ ) {
        if(i >= l && i <= r ) continue;
        

        int id = rec.back();
        int val = vec1[id];

        swap(vec2[id] , vec2[i]);

        if(vec2[id] == vec1[id] || vec2[i] == vec1[i]) {
            swap(vec2[id] , vec2[i]);
        }
        else {
            rec.pop_back();
        }
    }


    if(rec.size()) {
        cout<<"No\n";
        return 0;
    }
    cout<<"Yes\n";
    for(auto x : vec2) cout<<x<<" ";
    cout<<'\n';


    return 0;

}