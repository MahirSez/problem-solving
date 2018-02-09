#include <bits/stdc++.h>
#define ll      long long int
#define PI      acos(-1)
#define read    freopen("in.txt","r",stdin)
#define uu      first
#define vv      second
#define write   freopen("out.txt","w",stdout)
#define pii     pair<int,int>
#define INF     1e9
#define EPS     1e-8
#define MAX     1000006
#define MOD     1000000007
using namespace std;
int n , ara[MAX], sum[MAX], mp[MAX];
string str;
int main()
{
    cin>>n;
    for(int  i =1 ; i <= n ; i++ ) {
        cin>>ara[i];
        mp[ara[i]] = i;
    }

    cin>>str;
    for( int  i = 1 ; i < n ; i++ ) {

        sum[i] = (str[i-1]-'0');
    }
    for(int i = 1 ; i <=n ; i++ ) {

        sum[i] += sum[i-1];
    }
    bool flg = true;
    for(int  i = 1 ; i <= n ;i++ ) {


        if( ara[i] > i ) {

            //cout<<i<<" "<<ara[i]<<" "<<mp[i]<<" "<<sum[mp[i]-1]<<" "<<sum[i-1]<<" "<<endl;

            if(sum[ara[i]-1] - sum[i-1] != (ara[i]-i) )
                flg = false;
        }
    }
    if( flg ) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
