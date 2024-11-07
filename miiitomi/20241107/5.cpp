// https://atcoder.jp/contests/abc083/tasks/arc088_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    string S;
    cin >> S;
    int N = S.size(), ans = N;
    for (int i = 0; i < N-1; i++) {
        if (S[i] == S[i+1]) continue;
        ans = min(ans, max(i+1, N-i-1));
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
