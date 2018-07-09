#include <bits/stdc++.h>
#define ll      	long long int
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
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n ;
ll ara[MAX];
vector<ll>v;
map<ll , int>mp;
int main()
{
    fastRead;
    cin>>n;

    for(int i =0 ; i<34 ; i++) {
        v.push_back(1LL<<i);
    }
//    cout<<v.size()<<endl;

    for(int i =0 ; i< n ; i++ ) {
        cin>>ara[i];
        mp[ara[i]]++;
    }

    int cnt = 0;
    for(int j =0; j< n ; j ++ ) {
        ll tmp = ara[j];
        bool ok = false;
        for(int i =0 ; i < v.size() ; i++ ) {

            if( v[i] < tmp ) continue;
            else if( v[i] == tmp && mp[tmp] > 1) {
                ok = true;
                break;
            }
            else if( v[i] > tmp) {
                if(v[i]-tmp == tmp && mp[v[i]-tmp]>1) {
                    ok = true;
                    break;
                }
                else if( v[i] -tmp != tmp && mp[v[i]-tmp] ) {
                    ok = true;
                    break;
                }
            }
        }
        if( !ok) {
//            cout<<tmp<<endl;
            cnt++;
        }
    }

    cout<<cnt<<endl;
    return 0;
}
