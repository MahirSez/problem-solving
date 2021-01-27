//#undef DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll llinf = (1ll<<61)-1;
#define sz(a) int(a.size())
#define all(x) begin(x), end(x)
#ifdef DEBUG
const int DEBUG_END = 26;
#define DOS cout
#include <debug.h>
#else
#define bug(args...) void()
#define cbug(a, args...)
#endif
#define ASSERT(a, o, b, args...) if (!((a)o(b))) bug(a, b, ##args), assert((a)o(b));
#define fi first
#define se second
const int inf = 1000000007, M = 200005;
int TC = 1, CN, n, m, a, b, s[M];

signed main() { cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit); cout.precision(11), cout.setf(ios::fixed);
    cin >> TC;// inputAll + resetAll -> solution
    auto kase = [&]()->void {
        cin >> n >> m >> a >> b;
        for (int i = 0; i < m; i++) {
            cin >> s[i];
        }
        sort(s, s+m);
        int pt = min(m, abs(a-b)-1), et = a < b ? b-1 : n-b;//bug(pt, et);
        for (int i = 0; i < pt; i++) {
            if (i) s[i] = max(s[i], s[i-1]+1);
            if (s[i]+1 > et) {
                cout << i << '\n';
                return;
            }
        }
        cout << pt << '\n';
    };
    while (CN++!=TC) kase();
}