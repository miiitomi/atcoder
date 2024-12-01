// https://atcoder.jp/contests/abc277/tasks/abc277_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N, X;
    cin >> N >> X;
    for (int i = 1; i <= N; i++) {
        int p;
        cin >> p;
        if (p == X) {
            cout << i << endl;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
