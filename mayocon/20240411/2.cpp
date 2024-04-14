// https://atcoder.jp/contests/abc121/tasks/abc121_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> V(N);
    for (int i = 0; i < N; i++) cin >> V[i].first >> V[i].second;
    sort(V.begin(), V.end());
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll x = min(M, V[i].second);
        ans += V[i].first * x;
        M -= x;
        if (M == 0) break;
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
