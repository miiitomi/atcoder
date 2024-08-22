// https://atcoder.jp/contests/abc126/tasks/abc126_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll M, K;
    cin >> M >> K;

    if (M <= 1) {
        if (K == 0) {
            for (int x = 0; x <= M; x++) cout << x << " " << x << " ";
            cout << "\n";
        } else {
            cout << -1 << "\n";
        }
        return;
    }

    if (K < (1LL << M)) {
        for (ll x = 0; x < (1LL << M); x++) {
            if (x == K) continue;
            cout << x << " ";
        }
        cout << K << " ";
        for (ll x = (1LL << M)-1; x >= 0; x--) {
            if (x == K) continue;
            cout << x << " ";
        }
        cout << K << "\n";
    } else {
        cout << -1 << endl;
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
