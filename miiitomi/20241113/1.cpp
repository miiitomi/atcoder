// https://atcoder.jp/contests/abc109/tasks/abc109_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int a, b;
    cin >> a >> b;
    for (int c = 1; c <= 3; c++) {
        if (a*b*c % 2 == 1) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
