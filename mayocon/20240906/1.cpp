// https://atcoder.jp/contests/abc305/tasks/abc305_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];
    int a = INF, b = -INF, c = INF, d = -INF;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '.') continue;
            a = min(a, i);
            b = max(b, i);
            c = min(c, j);
            d = max(d, j);
        }
    }

    for (int x = a; x <= b; x++) {
        for (int y = c; y <= d; y++) {
            if (S[x][y] == '.') {
                cout << x+1 << " " << y+1 << endl;
                return;
            }
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
