// https://atcoder.jp/contests/typical90/tasks/typical90_ab
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

struct TwoDimensionalImos {
    ll H, W;
    vector<vector<ll>> S;
    TwoDimensionalImos(ll h, ll w) {
        H = h;
        W = w;
        S.assign(H+1, vector<ll>(W+1, 0));
    }

    void add(ll xl, ll xr, ll yl, ll yr, ll a) {
        // [xl, xr) × [yl, yr) に a を足す
        S[xl][yl] += a;
        S[xl][yr] -= a;
        S[xr][yl] -= a;
        S[xr][yr] += a;
    }

    void run() {
        for (int h = 0; h <= H; h++) {
            for (int w = 0; w < W; w++) {
                S[h][w+1] += S[h][w];
            }
        }
        for (int w = 0; w <= W; w++) {
            for (int h = 0; h < H; h++) {
                S[h+1][w] += S[h][w];
            }
        }
    }
};

void solve() {
    ll N;
    cin >> N;
    TwoDimensionalImos T(1000, 1000);
    for (int i = 0; i < N; i++) {
        ll lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        T.add(lx, rx, ly, ry, 1);
    }
    T.run();
    vector<ll> cnt(N+1, 0);
    for (int h = 0; h < 1000; h++) {
        for (int w = 0; w < 1000; w++) {
            cnt[T.S[h][w]]++;
        }
    }
    for (int k = 1; k <= N; k++) {
        cout << cnt[k] << "\n";
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
