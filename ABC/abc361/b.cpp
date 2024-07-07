#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

bool is_ok(int l1, int r1, int l2, int r2) {
    if (r2 <= l1 || r1 <= l2) return false;
    return true;
}

void solve() {
    vector<int> v(6), w(6);
    for (int i = 0; i < 6; i++) cin >> v[i];
    for (int j = 0; j < 6; j++) cin >> w[j];

    bool ok = true;
    for (int i = 0; i < 3; i++) if (!is_ok(v[i], v[i+3], w[i], w[i+3])) ok = false;

    if (ok) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
