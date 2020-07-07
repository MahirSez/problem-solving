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
    map<string,int>mp;
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        mp[s]++;
    }
    cout<<"AC x "<<mp["AC"]<<'\n';
    cout<<"WA x "<<mp["WA"]<<'\n';
    cout<<"TLE x "<<mp["TLE"]<<'\n';
    cout<<"RE x "<<mp["RE"]<<'\n';
    return 0;
    
}