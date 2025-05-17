#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll H, W, N;
    cin >> H >> W >> N;
    vector<set<ll>> R(H), C(W);
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        x--; y--;
        R[x].insert(y);
        C[y].insert(x);
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int k;
        cin >> k;
        if (k == 1) {
            int x;
            cin >> x;
            x--;
            cout << (int)R[x].size() << "\n";
            for (int y: R[x]) C[y].erase(x);
            R[x] = {};
        } else {
            int y;
            cin >> y;
            y--;
            cout << (int)C[y].size() << "\n";
            for (int x: C[y]) R[x].erase(y);
            C[y] = {};
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
