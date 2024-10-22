// https://atcoder.jp/contests/abc078/tasks/arc085_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N;
vector<ll> a;
map<pair<ll,ll>, ll> mpx, mpy;

ll f(pair<ll,ll> p, bool is_x) {
    if (is_x) {
        if (mpx.contains(p)) return mpx[p];
        if (p.first == N-1) return mpx[p] = abs(p.second - a[N-1]);
        ll res = -INF;
        for (int i = p.first; i <= N-1; i++) {
            ll tmp;
            if (i == N-1) tmp = f({N-1, p.second}, true);
            else tmp = f({i+1, a[i]}, false);
            res = max(res, tmp);
        }
        return mpx[p] = res;
    } else {
        if (mpy.contains(p)) return mpy[p];
        if (p.first == N-1) return mpy[p] = abs(p.second - a[N-1]);
        ll res = INF;
        for (int i = p.first; i <= N-1; i++) {
            ll tmp;
            if (i == N-1) tmp = f({N-1, p.second}, false);
            else tmp = f({i+1, a[i]}, true);
            res = min(tmp, res);
        }
        return mpy[p] = res;
    }
}


void solve() {
    ll Z, W;
    cin >> N >> Z >> W;
    a.resize(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    cout << f(make_pair(0, W), true) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
