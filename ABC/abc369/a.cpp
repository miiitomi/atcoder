#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

bool tousa(int p, int q, int r) {
    return q-p == r-q;
}

void solve() {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for (int x = -1000; x <= 1000; x++) {
        if (tousa(a, b, x) || tousa(a, x, b) || tousa(b, a, x) || tousa(b, x, a) || tousa(x, a, b) || tousa(x, b, a)) {
            ans++;
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
