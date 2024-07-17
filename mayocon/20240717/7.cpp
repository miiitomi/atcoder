// https://atcoder.jp/contests/abc139/tasks/abc139_f
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
    for (int i = 0; i < N; i++) cin >> V[i].first >> V[i].second;
    sort(V.begin(), V.end(), [](const pair<ll,ll> &l, const pair<ll,ll> &r) {return atan2(l.second, l.first) < atan2(r.second, r.first);});

    double ans = -1;
    for (int i = 0; i < N; i++) {
        for (int k = 1; k <= N; k++) {
            int j = i;
            ll X = 0, Y = 0;
            for (int l = 0; l < k; l++) {
                X += V[j].first;
                Y += V[j].second;
                j = (j + 1) % N;
            }
            ans = max(ans, sqrt(X*X + Y*Y + 0.0));
        }
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
