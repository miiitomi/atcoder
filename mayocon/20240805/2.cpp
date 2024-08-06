// https://atcoder.jp/contests/abc358/tasks/abc358_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M;
    cin >> N >> M;
    multiset<ll> S;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        S.insert(a);
    }
    ll ans = 0;
    for (int i = 0; i < M; i++) {
        ll b;
        cin >> b;
        auto iter = S.lower_bound(b);
        if (iter == S.end()) {
            cout << -1 << endl;
            return;
        }
        ans += *iter;
        S.erase(iter);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
