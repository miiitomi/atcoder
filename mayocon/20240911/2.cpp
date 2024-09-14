// https://atcoder.jp/contests/abc315/tasks/abc315_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<pair<ll,ll>> V(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i].second >> V[i].first;
    }
    sort(V.begin(), V.end());
    ll ans = -INF;
    for (int i = 0; i < N-1; i++) {
        ll tmp;
        if (V[i].second == V.back().second) {
            tmp = V.back().first + V[i].first/2;
        } else {
            tmp = V.back().first + V[i].first;
        }
        ans = max(ans, tmp);
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
