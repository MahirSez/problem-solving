#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e5 + 5;
const double PI  = acos(-1);

vector<double>vec;

int main()
{
    fastRead;
    int n ;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) {
        
        double x , y;
        cin>>x>>y;
        vec.push_back(atan2(y,x)*180.0/PI);
    }

    sort(vec.begin() , vec.end());
    
    double gap = 360.0 - vec[n-1] + vec[0];
    for(int i =0 ; i < n-1 ; i++ ) {
        gap = max(gap , vec[i+1] - vec[i]);
    }
    printf("%0.9f\n",360.0 - gap);
    return 0;
    
}
    