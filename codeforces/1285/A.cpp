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
    int n;
    cin>>n;
    string str;
    cin>>str;
    int a = 0, b = 0;
    for(auto x : str ) {
        if(a == 'L') a++;
        else b++;
    }
    cout<<(a+b+1)<<'\n';
    return 0;
    
}