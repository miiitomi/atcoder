// https://atcoder.jp/contests/abc269/tasks/abc269_d
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
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
    dsu U(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (U.same(i, j)) continue;
            if (Y[i] == Y[j]) {
                if (abs(X[i]-X[j]) <= 1) U.merge(i, j);
            } else if (Y[i]+1 == Y[j]) {
                if (X[j] == X[i] || X[j] == X[i]+1) U.merge(i, j);
            } else if (Y[i]-1 == Y[j]) {
                if (X[j] == X[i] || X[j] == X[i]-1) U.merge(i, j);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) ans += (U.leader(i) == i);

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
