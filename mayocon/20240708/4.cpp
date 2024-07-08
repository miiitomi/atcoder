// https://atcoder.jp/contests/abc195/tasks/abc195_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<pair<ll, ll>> V(N, {0, 0});
    for (int i = 0; i < N; i++) cin >> V[i].first >> V[i].second;
    sort(V.begin(), V.end(), [](const pair<ll,ll> &p, const pair<ll,ll> &q) {return p.second > q.second;});
    vector<ll> X(M);
    for (int i = 0; i < M; i++) cin >> X[i];

    while (Q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        multiset<ll> S;
        for (int i = 0; i < M; i++) if (!(l <= i && i <= r)) S.insert(X[i]);
        ll ans = 0;
        for (auto &p : V) {
            auto iter = S.lower_bound(p.first);
            if (iter != S.end()) {
                ans += p.second;
                S.erase(iter);
            }
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
