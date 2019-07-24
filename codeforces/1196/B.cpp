#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000006
using namespace std;
int n , k ;
vector<int>num , odd;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin>>q;
    while( q--) {

        cin>>n>>k;
        num.clear();
        odd.clear();
        for(int i =0 ; i < n ; i++) {
            int tmp;
            cin>>tmp;

            num.push_back(tmp);
            if( tmp & 1) odd.push_back(i);
        }

        int sz = odd.size();
        int cnt = sz;
        if( sz < k ) {
            cout<<"NO\n";
            continue;
        }

        vector<int>ans;
        for(int i =0 ; i < n && k >1 ; i++ ) {

            if(num[i] & 1 ) {
                ans.push_back(i+1);
                cnt--;
                k--;
            }
        }

        if( cnt %2 ==0 ) {
            cout<<"NO\n";
            continue;
        }
        ans.push_back(n);
        cout<<"YES\n";
        for(auto x : ans) cout<<x<<" ";
        cout<<'\n';


    }
    return 0;
}
