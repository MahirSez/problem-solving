#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll			pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n ;
vector<int>v;
int cnt , input,ans;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
    srand(time(NULL));
    fastRead;
    cin>>n;
    int lo = 0 , hi = 1e9;
    while( lo <= hi ) {
        int mid = (lo+hi)>>1;
        cout<<"> "<<mid<<endl;  
        cnt++;
        // cout<<"---"<<cnt<<endl;
        cin>>input;
        if( input ==1) {
            lo = mid+1;
        }
        else {
            hi = mid - 1;
            ans = mid;
        }
    }

    set<int>s;
    for(int i = cnt  ,tmp = 1; i <60 && tmp <= n; i++ ) {
        int tmp1 = rng()%n +1;
        
        if(s.find(tmp1) == s.end() ) {
            cout<<"? "<<tmp1<<endl;
            cin>>input;
            v.push_back(input);
            s.insert(tmp1);
            tmp++;
        }
    }
    sort(v.begin() , v.end());
    if( v.back() != ans ) v.push_back(ans);
    
    int tmp = v[1] - v[0];
    for(int i =1 ; i < (int)v.size() ; i++ ) {
        tmp = __gcd(tmp , v[i] - v[i-1]);
    }
    int st = ans  - (n-1)* tmp;
    cout<<"! "<<st<<" "<<tmp<<endl;
    return 0;
}