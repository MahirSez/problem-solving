#include <bits/stdc++.h>
#define ll			long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
int a , b , ans;
vector<int>v;

int main()
{
    cin>>a>>b;
    while( b>=a) {

        if( b == a) {
            cout<<"YES"<<endl;
            reverse(v.begin() , v.end() );
            cout<<v.size() +1<<endl;
            cout<<a<<" ";
            for(int i =0 ; i < v.size() ; i++)
                cout<<v[i]<<" ";
            cout<<endl;
            return 0;
        }

        if( b%10==1 ) {
            v.push_back(b);
            b/=10;
        }
        else if( !(b&1) ) {
            v.push_back(b);
            b/=2;
        }
        else break;
    }
    cout<<"NO"<<endl;
    return 0;
}
