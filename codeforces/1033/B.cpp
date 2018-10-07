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
int t ;
ll a , b;
vector<ll>v;
int prm[MAX];
void seive() {

    for(ll i = 2 ; i< MAX ; i++ ) {
        if( prm[i] ==0 ) {
            for(ll j = i*i ; j < MAX ; j+=i) {
                prm[j] = 1;
            }
        }
    }
    for(int i =2 ; i <MAX; i++ ) {
        if( prm[i] ==0) v.push_back(i);
    }
}

bool check(ll tmp) {
//    cout<<tmp<<endl;
//    for(int i =0 ; i < 10 ; i++ ) cout<<v[i]<<" ";
//    cout<<endl;
    for(int i =0 ; i <v.size(); i++  ) {
        if( tmp == v[i]) return true;
        if( tmp%v[i]==0) return false;
    }
    return true;
}

int main()
{
    seive();
    cin>>t;
    while(t--) {
        cin>>a>>b;
//        cout<<a-b<<endl;
        if( a-b ==1LL) {

            bool ok= check(2*b+1LL);
            if( ok ) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}

