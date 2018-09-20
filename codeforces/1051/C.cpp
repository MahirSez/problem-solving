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
#define MAX     	10004
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n ;
int ara[MAX] , cnt[MAX];
vector<int>one ,two , more;
int col[MAX];
int main()
{
    cin>>n;
    for(int i =0 ; i < n ; i++) {
        cin>>ara[i];
        cnt[ara[i]]++;
    }
    for(int i =1 ; i<= 100 ; i++) {
        if( cnt[i] ==1) {
            one.push_back(i);
        }
        else if( cnt[i] ==2 ) {
            two.push_back(i);
            col[i] = 2;
        }
        else if( cnt[i] > 2) {
            more.push_back(i);
        }
    }

    int nn = one.size();
    if( !(nn&1) ) {
        cout<<"YES"<<endl;
        for(int i =0 ; i < nn / 2; i++ ) {
            col[one[i]] = 1;
//            cout<<i<<endl;
        }
        for(int i = nn/2 ; i < nn; i++ ) {
            col[one[i]] = 2;
//            cout<<"--->"<<i<<endl;
        }

        for(int i =0 ;i < n ; i++  ) {
//            cout<<ara[i]<<" "<<col[ara[i]]<<endl;
            if( col[ara[i]] & 1 ) {
                cout<<'A';
            }
            else cout<<'B';
        }
        cout<<endl;
        return 0;
    }

    int mm = more.size();
    if(mm == 0) {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;

    for(int i =0 ; i < nn / 2; i++ ) {
        col[one[i]] = 1;
//            cout<<i<<endl;
    }
    for(int i = nn/2 ; i < nn; i++ ) {
        col[one[i]] = 2;
//            cout<<"--->"<<i<<endl;
    }
    bool ok = false;
    for(int i =0 ; i< n ;i++ ) {
        int tmp = ara[i];
        if( col[tmp] == 1) {
            cout<<'A';
        }
        else if( col[tmp] == 2) {
            cout<<'B';
        }
        else {
            if( !ok ) {
                cout<<'A';
                ok = 1;
            }
            else cout<<'B';
        }
    }

    cout<<endl;
    return 0;
}
