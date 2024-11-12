// https://atcoder.jp/contests/abc251/tasks/abc251_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, W;
    cin >> N >> W;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<bool> cnt(W+1, false);
    for (int i = 0; i < N; i++) {
        if (A[i] <= W) cnt[A[i]] = true;
        for (int j = i+1; j < N; j++) {
            if (A[i] + A[j] <= W) cnt[A[i]+A[j]] = true;
            for (int k = j+1; k < N; k++) {
                if (A[i]+A[j]+A[k] <= W) cnt[A[i]+A[j]+A[k]] = true;
            }
        }
    }
    ll ans = 0;
    for (bool b : cnt) ans += b;
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
