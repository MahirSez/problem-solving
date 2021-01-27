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
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define YN(x) (x) ? (yes) : (no)

inline int ceillog2(unsigned long long x) {
    return !x ? -1 : x==1 ? 0 : 64-__builtin_clzll(x-1);
}
template <class S, S (*op)(S, S, int, int, int), S (*e)()> class segtree {//{
  public:
    segtree() : segtree(0) {}
    segtree(int _nn, S val = e(), bool oneBased = 1) : segtree(std::vector<S>(_nn, val)) { if (val != e() and oneBased) set(0, e()); }
    segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = ceillog2(_n);
        size = _n ? 1 << log : 0;   // shifting by -1 is undefined
        d = std::vector<S>(2 * size, e());
        range.resize(2 * size);
        copy_n(begin(v), _n, begin(d) + size);
        for (int i = 0; i < size; ++i) range[size + i] = {i, i+1};
        for (int i = size - 1; i >= 1; --i) {
            range[i] = {range[i << 1].first, range[i << 1 | 1].second};
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; ++i) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) { ++r;
        assert(0 <= l && l <= r && r <= _n);

        int ql = l, qr = r;

        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l], ql, range[l].first, range[l].second), ++l;
            if (r & 1) --r, smr = op(d[r], smr, range[r].first, range[r].second, qr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr, ql, range[r].first, qr);
    }

    S all_prod() { return d[1]; }

    template <bool (*f)(S, int, int)> int max_right(int l) {
        return max_right(l, [](S x, int cl, int cr) { return f(x, cl, cr); });
    }
    template <class F> int max_right(int l, F f) {
        assert(0 <= l && l <= _n);
        assert(f(e(), 0, 0));
        if (l == _n) return _n;
        int ql = l;
        l += size;
        S sm = e();
        do {
            while (!(l & 1)) l >>= 1;
            if (!f(op(sm, ql, range[l].first, range[l].second), ql, range[l].second)) {
                while (l < size) {
                    l <<= 1;
                    auto tmp = op(sm, d[l], ql, range[l].first, range[l].second);
                    if (f(tmp, ql, range[l].second)) {
                        sm = tmp;
                        ++l;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l], ql, range[l].first, range[l].second);
            ++l;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S, int, int)> int min_left(int r) {
        return min_left(r, [](S x, int cl, int cr) { return f(x, cl, cr); });
    }
    template <class F> int min_left(int r, F f) { ++r;
        assert(0 <= r && r <= _n);
        assert(f(e(), 0, 0));
        if (r == 0) return 0;
        int qr = r;
        r += size;
        S sm = e();
        do {
            --r;
            while (r > 1 && (r & 1)) r >>= 1;
            if (!f(op(d[r], sm, range[r].first, range[r].second, qr), range[r].first, qr)) {
                while (r < size) {
                    r = r << 1 | 1;
                    auto tmp = op(d[r], sm, range[r].first, range[r].second, qr);
                    if (f(tmp, range[r].first, qr)) {
                        sm = tmp;
                        --r;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm, range[r].first, range[r].second, qr);
        } while ((r & -r) != r);
        return 0;
    }

    string toString(int nd = 26, bool printRange = false) {
        auto pad2 = [](const int &x)->string { return (" "+(x>=10)) + std::to_string(x); };
        ostringstream os;
        os << '\n';
        if (printRange) {
            for (int i = 0; i <= nd; ++i) {
                for (int j = i; j <= nd; ++j)
                    os << pad2(i) << ' ' << pad2(j) << " =  " << prod(i, j) << '\n';
            }
        } else {
            for (int i = 0; i <= nd; ++i) {
                os << pad2(i) << " =  " << prod(i, i) << '\n';
            }
        }
        return os.str();
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<pair<int,int>> range;

    void update(int i) { d[i] = op(d[i << 1], d[i << 1 | 1], range[i].first, range[i << 1].second, range[i].second); }
};//}

#define unus __attribute__((unused))
namespace seg { // ranges are [l, r) here unlike update / query.
    using S = int;
    S e() { return 0; }
    S op(S lval, S rval, unus int l, unus int mid, unus int r) { return max(lval, rval); }  // merging [l, mid) and [mid, r)
    using tree = segtree<S, op, e>;
}
using segtr = seg::tree;

const int inf = 1000000007, N = 500005;
int TC = 1, CN, n, a[N];

signed main() { cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit); cout.precision(11), cout.setf(ios::fixed);
    cin >> TC;// inputAll + resetAll -> solution
    auto kase = [&]()->void {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        segtr st(n+1);

        stack<int> p;
        p.push(0);
        for (int i = 1; i <= n; i++) {
            st.set(a[i], st.prod(0, a[i])+1);
            while (!p.empty() and p.top()<=a[i]) {//bug(i, p.top());
                if (p.top() != a[i]) st.set(p.top(), st.prod(p.top(), p.top())+1);              //bug(st.toString(n));;
                p.pop();
            }
            p.push(a[i]);
        }
        cout << st.all_prod() << '\n';
    };
    while (CN++!=TC) kase();
}