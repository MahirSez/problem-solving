#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;


const int INF = 1e9;
const ll MOD = 1e9 + 7;
const int N = 2e5 + 5;
int ara[N], rec1[N], rec2[N];


int k[N], l[N], r[N];

vector<int>lt[N], rt[N];


int main() {
    fastio;
    
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;

		for(int i =1; i <=n ; i++ ) lt[i].clear(), rt[i].clear();

        ll ans = 0;

        for(int i =1 ; i <= n ; i++ ) {
            cin>>k[i]>>l[i]>>r[i];
            int mn = min(l[i], r[i]);
			ans += mn;
			l[i] -= mn;
			r[i] -= mn;

			if(k[i] == n) ans += l[i];
            else if(l[i]) lt[ k[i] ].push_back(l[i]);
            else rt[ n - k[i] ].push_back(r[i]);
        }
		// cout<<ans<<'\n';

		priority_queue<int, vector<int>, greater<int> >pq1, pq2;

        int baki1 = 0, baki2 = 0;

        for(int i =1 ; i <=n ;i++ ) {

            baki1++;
            baki2++;

            sort(lt[i].rbegin(), lt[i].rend());
            sort(rt[i].rbegin(), rt[i].rend());

            for(auto x : lt[i]) {
				if(baki1) {
					pq1.push(x);
					baki1--;
				}
				else if(x > pq1.top() ) {
					pq1.pop();
					pq1.push(x);
				}
			}

            for(auto x : rt[i]) {
				if(baki2) {
					pq2.push(x);
					baki2--;
				}
				else if(x > pq2.top() ) {
					pq2.pop();
					pq2.push(x);
				}
			}          
        }

		while(!pq1.empty()) {
			// cout<<pq1.top()<<'\n';
			ans += pq1.top();
			pq1.pop();
		}
		// cout<<'\n';
		while(!pq2.empty()) {
			// cout<<pq2.top()<<'\n';
			ans += pq2.top();
			pq2.pop();
		}

        cout<<ans<<'\n';
    }
    return 0;
}
