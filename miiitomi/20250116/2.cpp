// https://atcoder.jp/contests/abc047/tasks/abc047_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll W, H, N;
    cin >> W >> H >> N;
    vector<vector<ll>> A(W, vector<ll>(H, 1));
    while (N--) {
        ll x, y, a;
        cin >> x >> y >> a;
        ll lx=0, rx=W-1, ly=0, ry=H-1;
        if (a == 1) rx = x-1;
        else if (a == 2) lx = x;
        else if (a == 3) ry = y-1;
        else ly = y;
        for (int i = lx; i <= rx; i++) {
            for (int j = ly; j <= ry; j++) {
                A[i][j] = 0;
            }
        }
    }
    ll cnt = 0;
    for (int i = 0; i < W; i++) for (int j = 0; j < H; j++) cnt += A[i][j];
    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
