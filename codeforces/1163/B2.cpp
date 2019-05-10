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
#define MAX     	100005
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , ara[MAX] , cnt[MAX] , fre[MAX];
set<int>s;
int main()
{
	fastRead;
	cin>>n;
	for(int i =0 ; i < n ; i++ ) cin>>ara[i] , cnt[ara[i]]++ ;

	for(int i =0 ; i < n ; i++ )  s.insert(cnt[ara[i]]);

	for(int i = 0 ; i < MAX ; i++) {
		if( cnt[i] > 0) fre[cnt[i]]++;
	}

    for(int i = n-1 ; i>=0 ; i--) {

        if(s.size() == 1  && *s.begin() == 1) {
			cout<<i+1<<endl;
			return 0;
        }
        if( s.size() ==1  && cnt[ara[i]] == i+1) {
			cout<<i+1<<endl;
			return 0;
        }

        if( s.size() == 2) {

            auto it = s.begin();
            int cnt1 = *it;
            it++;
            int cnt2 = *it;
            if( cnt2 - cnt1 == 1 && fre[cnt2] == 1) {
				cout<<i+1<<endl;
				return 0;
            }
            if( cnt1 == 1 && fre[1] ==1 ) {
				cout<<i+1<<endl;
				return 0;
            }
        }

        int num = ara[i];

        int nowCnt = cnt[ara[i]];

        fre[nowCnt]--;

        if( fre[nowCnt] == 0 ) s.erase(nowCnt);

        cnt[ara[i]]--;

        nowCnt = cnt[ara[i]];
        if( nowCnt > 0 ) {
			s.insert(nowCnt);
			fre[nowCnt]++;
        }



    }
	assert(0);
	return 0;

}
