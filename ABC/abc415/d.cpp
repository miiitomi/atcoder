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
    vector<pair<ll,ll>> P(M);
    for (int i = 0; i < M; i++) cin >> P[i].first >> P[i].second;
    sort(P.begin(), P.end(), [](const auto &l, const auto &r) {return l.second-l.first > r.second-r.first;});
    ll ans = 0;
    for (const auto &p: P) {
        ll left = 0, right = N/(p.first-p.second) + 1;
        while (right - left > 1) {
            ll m = (left + right)/2;
            if (N - (m-1)*(p.first - p.second) - p.first < 0) {
                right = m;
            } else {
                left = m;
            }
        }
        ans += left;
        N = N - left * (p.first - p.second);
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
