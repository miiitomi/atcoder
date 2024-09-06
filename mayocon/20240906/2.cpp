// https://atcoder.jp/contests/abc224/tasks/abc224_c
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

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            for (int k = j+1; k < N; k++) {
                vector<pair<ll,ll>> v{V[i], V[j], V[k]};
                sort(v.begin(), v.end());
                if ((v[1].second-v[0].second)*(v[2].first-v[0].first) == (v[2].second-v[0].second)*(v[1].first-v[0].first)) continue;
                ans++;
            }
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
