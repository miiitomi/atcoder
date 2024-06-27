// https://atcoder.jp/contests/abc195/tasks/abc195_b
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll A, B, W;
    cin >> A >> B >> W;
    W *= 1000;
    ll max_v = -1, min_v = 1e+9;
    for (ll n = 1; n <= W; n++) {
        if (n*A <= W && W <= n*B) {
            max_v = max(max_v, n);
            min_v = min(min_v, n);
        }
    }

    if (max_v != -1) {
        cout << min_v << " " << max_v << endl;
    } else {
        cout << "UNSATISFIABLE" << endl;
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
