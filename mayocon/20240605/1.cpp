// https://atcoder.jp/contests/abc229/tasks/abc229_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, W;
    cin >> N >> W;
    vector<pair<ll,ll>> V(N);
    for (int i = 0; i < N; i++) cin >> V[i].first >> V[i].second;
    sort(V.begin(), V.end());

    ll ans = 0;
    while (W >= 1 && !V.empty()) {
        auto p = V.back();
        V.pop_back();
        ll x = min(W, p.second);
        ans += x * p.first;
        W -= x;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
