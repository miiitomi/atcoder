// https://atcoder.jp/contests/abc065/tasks/arc076_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<mint> F(1e+6, 1);

void solve() {
    ll N, M;
    cin >> N >> M;
    if (abs(N-M) >= 2) {
        cout << 0 << endl;
        return;
    }
    mint ans = F[N] * F[M];
    if (N == M) ans *= 2;
    cout << ans.val() << endl;
}

int main() {
    for (int x = 1; x < 1e+6; x++) F[x] = F[x-1]*x;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
