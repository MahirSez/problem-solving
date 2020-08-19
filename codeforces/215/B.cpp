#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const ll N = 1e7 + 6;

int main()  {
    fastio;
    
    int n;
    cin>>n;
    vector<double>out(n) ;  
    for(auto &x : out) cin>>x;
    int m;
    cin>>m;
    vector<double>roout(m);
    for(auto &x : roout) cin>>x;

    int k;
    cin>>k;
    vector<double>roin(k);
    for(auto &x : roin ) cin>>x;

    double A , B;
    cin>>A>>B;


    sort(   out.begin() , out.end());
    sort(   roout.begin() , roout.end());
    sort(   roin.begin() , roin.end());



    double r1 = out.back();
    double ro1 = roout.back();
    double ro2 = roin[0];

    // cout<<r1<<" "<<ro1<<" "<<ro2<<'\n';
    
    double tmp = A/B + ro1/ro2;

    r1 = r1 * r1;
    double r2 = r1 * ro1  / (ro2*tmp);
    cout<<setprecision(10)<<fixed<<sqrt(r2)<<'\n';

}