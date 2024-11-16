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
    ll ans = (N-1)*N / 2;
    vector<pair<ll,ll>> P(M);
    for (int i = 0; i < M; i++) {
        cin >> P[i].first;
        P[i].first--;
    }
    for (int i = 0; i < M; i++) {
        cin >> P[i].second;
        ans -= P[i].first * P[i].second;
    }
    P.push_back({N, 0});
    sort(P.begin(), P.end());
    bool ok = (P[0].first == 0);
    for (int i = 0; i < M; i++) {
        if (P[i+1].first - P[i].first > P[i].second) ok = false;
        P[i+1].second += P[i].second - (P[i+1].first - P[i].first);
    }
    if (ok && P.back().second == 0) cout << ans << endl;
    else cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
