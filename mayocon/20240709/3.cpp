// https://atcoder.jp/contests/abc302/tasks/abc302_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M, D;
    cin >> N >> M >> D;
    vector<ll> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int j = 0; j < M; j++) cin >> B[j];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int j = -1;
    ll ans = -1;
    for (ll a : A) {
        while (j+1 <= M-1 && B[j+1] <= a + D) {
            j++;
        }
        if (abs(a - B[j]) <= D) {
            ans = max(ans, a+B[j]);
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
