#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;


const int INF = 1e9;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 3;
int ara[N];

int main() {
    int n;
    cin>>n;

    for(int i =1 ; i <=100 ; i++ )     {
        for(int j =1 ; j <= 100 ; j++ ) {
            for(int k =1 ; k <= 100; k++ ) {
                int tmp = i*i + j*j + k*k + i*j + i*k + j*k;
                ara[tmp]++;
            }
        }
    }
    for(int i =1 ; i <=n ; i++ ) cout<<ara[i]<<'\n';

    return 0;
}