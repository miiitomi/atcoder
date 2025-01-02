// https://atcoder.jp/contests/typical90/tasks/typical90_d
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
    vector<vector<ll>> A(H, vector<ll>(W));
    vector<ll> R(H, 0), C(W, 0);
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            cin >> A[h][w];
            R[h] += A[h][w];
            C[w] += A[h][w];
        }
    }
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            cout << R[h] + C[w] - A[h][w] << " ";
        }
        cout << "\n";
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
