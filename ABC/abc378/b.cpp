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
    vector<int> q(N), r(N);
    for (int i = 0; i < N; i++) {
        cin >> q[i] >> r[i];
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int t, d;
        cin >> t >> d;
        t--;
        if (d%q[t] <= r[t]) {
            cout << d + (r[t]-(d%q[t])) << endl;
        } else {
            cout << d + q[t]-d%q[t]+r[t] << endl;
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
