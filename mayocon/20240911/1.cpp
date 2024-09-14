// https://atcoder.jp/contests/abc170/tasks/abc170_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    vector<int> x(6, 0);
    for (int i = 1; i <= 5; i++) cin >> x[i];

    for (int i = 1; i <= 5; i++) {
        if (x[i] == 0) {
            cout << i << endl;
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
