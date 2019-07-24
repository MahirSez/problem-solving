#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000006
using namespace std;
int t , n , k;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;

    while( t-- ) {

        cin>>n>>k;
        vector<int>ara(n+1);


        string str;

        cin>>str;

        int ans = 1e9;

        for(int i =0 ; i < n ; i++) {

            if(i%3 ==0 && str[i] != 'R') ara[i+1] = 1;
            else if(i%3 ==1 && str[i] != 'G') ara[i+1] = 1;
            else if(i%3 ==2 && str[i] != 'B') ara[i+1] = 1;
            else ara[i+1] = 0;
        }

        for(int i =1 ; i <= n ; i++ ) ara[i] += ara[i-1];
        for(int i =1; i +k-1<= n ; i++ ) {
            ans = min(ans , ara[i+k-1] - ara[i-1]);
        }

        for(int i =0 ; i < n ; i++) {

            if(i%3 ==2 && str[i] != 'R') ara[i+1] = 1;
            else if(i%3 ==0 && str[i] != 'G') ara[i+1] = 1;
            else if(i%3 ==1 && str[i] != 'B') ara[i+1] = 1;
            else ara[i+1] = 0;
        }

        for(int i =1 ; i <=n ; i++ ) ara[i] += ara[i-1];
        for(int i =1; i +k-1<= n ; i++ ) {
            ans = min(ans , ara[i+k-1] - ara[i-1]);
        }

        for(int i =0 ; i < n ; i++) {

            if(i%3 ==1 && str[i] != 'R') ara[i+1] = 1;
            else if(i%3 ==2 && str[i] != 'G') ara[i+1] = 1;
            else if(i%3 ==0 && str[i] != 'B') ara[i+1] = 1;
            else ara[i+1] = 0;
        }

        for(int i =1 ; i <=n ; i++ ) ara[i] += ara[i-1];
        for(int i =1; i+k-1 <= n ; i++ ) {
            ans = min(ans , ara[i+k-1] - ara[i-1]);
        }

        cout<<ans<<'\n';
    }
    return 0;
}
