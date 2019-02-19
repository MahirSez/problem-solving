#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000006
using namespace std;
ll ara[MAX];
ll n , m;

bool ok(int k) {

    ll sum = 0;
    int koybar = (n-1)/k + 1;

    for(int i = 0 ; i  < koybar ; i++ ) {

        for(int j = i* k , cnt = 0 ; cnt < k && j < n ; j++,cnt++ ) {
            sum += max(ara[j] - i , 0LL);
        }
    }
    // cout<<k<<" "<<sum<<endl;
    return  (sum >= m);
}

int solve() {

    int lo = 1 , hi = n;
    int ans = n;

    while( lo<= hi) {

        int mid = (lo+hi)/2;

        if( ok(mid) ) {
            hi = mid-1;
            ans = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    ll sum = 0;
    for(int i =0 ; i < n ; i++ ) {
        cin>>ara[i];
        sum +=ara[i];
    }
    
    if(sum < m) {
        cout<<-1<<endl;
        return 0;
    }
    sort(ara , ara+ n);
    reverse(ara , ara + n);
    cout<<solve()<<endl;
    return 0;
}
