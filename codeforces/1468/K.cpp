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
const int inf = 1000000007;
int TC = 1, CN;
string s;
map<char, int> dr = {{'D', -1}, {'U', 1}}, dc = {{'L', -1}, {'R', 1}};

bool ok(int cr, int cc) {
    int r = 0, c = 0;
    for (auto &i : s) {
        int nr = r+dr[i], nc = c+dc[i];
        if (nr != cr or nc != cc) r = nr, c = nc;
    }
    return !r and !c;
}

signed main() { cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit); cout.precision(11), cout.setf(ios::fixed);
    cin >> TC;// inputAll + resetAll -> solution
    auto kase = [&]()->void {
        int cr = 0, cc = 0;
        cin >> s;
        for (auto &i : s) {
            cr += dr[i], cc += dc[i];
            if ((cr or cc) and ok(cr, cc)) {
                cout << cc << ' ' << cr << '\n';
                return;
            }
        }
        cout << "0 0\n";
    };
    while (CN++!=TC) kase();
}