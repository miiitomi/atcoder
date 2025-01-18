// https://atcoder.jp/contests/abc267/tasks/abc267_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M, tmp = 0, sum = 0;
    cin >> N >> M;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i < M) {
            sum += A[i];
            tmp += (i+1) * A[i];
        }
    }
    ll ans = tmp;
    for (int i = M; i < N; i++) {
        tmp += -sum + M*A[i];
        sum += A[i] - A[i-M];
        ans = max(ans, tmp);
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
