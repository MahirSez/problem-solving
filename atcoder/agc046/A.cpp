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
    int x;
    cin>>x;
    for(int i =1 ; ; i++ ) {
        if(360*i%x == 0) {
            cout<<360*i/x<<'\n';
            return 0;
        }
    }
    return 0;
    
}