#include<bits/stdc++.h>
using namespace std;

const int MAX =1e5 + 5;

double H , L , ans;
int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    
    cin>>H>>L;
    
    ans = (L*L - H*H) / (2.0 * H);
    printf("%0.9f\n",ans);
    return 0;
}
