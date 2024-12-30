// https://atcoder.jp/contests/abc098/tasks/arc098_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N;
    cin >> N;
    fenwick_tree<int> E(N), W(N);
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        if (c == 'E') E.add(i, 1);
        else W.add(i, 1);
    }
    int ans = 1e+9;
    for (int i = 0; i < N; i++) {
        ans = min(ans, W.sum(0, i)+E.sum(i+1, N));
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
