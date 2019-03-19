#include<bits/stdc++.h>
#define ll long long int
#define MAX 100005
using namespace std;
ll n , ara[MAX];

struct node {
    node* next[2];
    node() {
    	memset(next , 0 , sizeof next);
    }
}*root ;



void Insert(ll num) {

	node *rt = root;
	for(int i =50 ; i>=0 ; i--) {

        int id = bool(num&(1LL<<i) );
        if(rt->next[id] ==0 ) rt->next[id] = new node();

        rt = rt->next[id];
	}
}

ll totXor = 0;

ll query(ll num) {

	ll ans =0 ;

	node *rt = root;

    for(int i =50 ; i>=0; i--) {

        int id = bool(num & (1LL<<i) );

        if( rt->next[id^1] ) {
			ans = (ans<<1|1);
			rt = rt->next[id^1];
        }
        else {
			ans= ans<<1;
			rt = rt ->next[id];
        }
    }
    return ans;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	root = new node();
	cin>>n;
	for(int i =0 ; i < n ; i++ ) cin>>ara[i] ,totXor ^= ara[i];

    ll ans = totXor;

    ll tmpXor = 0;

    Insert(0);

    for(int i =0 ; i <n ; i++  ) {


        tmpXor ^= ara[i];

        Insert(tmpXor);

        ans = max(ans , query(totXor ^ tmpXor) ) ;
//		cout<<tmpXor<<" "<<(totXor^tmpXor)<<" "<<query(totXor^tmpXor)<<endl;
    }

    cout<<ans<<endl;
    return 0;

}
