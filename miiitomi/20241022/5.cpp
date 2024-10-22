// https://atcoder.jp/contests/abc045/tasks/arc061_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll H, W, N;
    cin >> H >> W >> N;
    set<pair<ll,ll>> S, T;
    for (int i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        S.insert(make_pair(a, b));
        for (ll r = max(a-2, 0LL); r <= min(a, H-3); r++) {
            for (ll c = max(b-2, 0LL); c <= min(b, W-3); c++) {
                T.insert(make_pair(r, c));
            }
        }
    }
    vector<ll> ans(10, 0);
    ans[0] = (H-2)*(W-2);
    for (auto &p : T) {
        ll cnt = 0;
        for (ll x = p.first; x <= p.first+2; x++) {
            for (ll y = p.second; y <= p.second+2; y++) {
                if (S.contains(make_pair(x, y))) cnt++;
            }
        }
        if (cnt >= 1) {
            ans[cnt]++;
            ans[0]--;
        }
    }
    for (ll a : ans) cout << a << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
