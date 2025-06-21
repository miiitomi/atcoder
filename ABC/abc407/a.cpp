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
    int ans = -1;
    double score = 1e+9;
    for (int x = 0; x <= 1000; x++) {
        double tmp = abs(x - (a+0.0)/(b+0.0));
        if (tmp < score) {
            score = tmp;
            ans = x;
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
