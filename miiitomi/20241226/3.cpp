// https://atcoder.jp/contests/abc278/tasks/abc278_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

template<typename T> struct TwoDimensionalCumulatedSum {
    int H, W;
    vector<vector<T>> A, S;

    void preprocessing() {
        // Preprocessing of S
        S.assign(H+1, vector<T>(W+1, 0));
        for (int h = 1; h <= H; h++) {
            for (int w = 1; w <= W; w++) {
                S[h][w] = A[h-1][w-1] + S[h-1][w] + S[h][w-1] - S[h-1][w-1];
            }
        }
    }

    TwoDimensionalCumulatedSum(vector<vector<T>> &V) {
        H = V.size();
        W = V[0].size();
        A = V;
        preprocessing();
    }

    TwoDimensionalCumulatedSum(int h, int w) {
        H = h;
        W = w;
        A.assign(H, vector<T>(W, 0));
    }

    void set(int h, int w, T x) {
        // If you update A[h][w] with this method, you need run preprocessing() later.
        A[h][w] = x;
    }

    ll query(int hl, int hr, int wl, int wr) {
        // Return the sum of A in [hl, hr) × [wl, wr). (Remark: Semi-opend interval!)
        return S[hr][wr] - S[hl][wr] - S[hr][wl] + S[hl][wl];
    }
};

void solve() {
    int H, W, N, h, w;
    cin >> H >> W >> N >> h >> w;
    vector<TwoDimensionalCumulatedSum<ll>> T(N, TwoDimensionalCumulatedSum<ll>(H, W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int a;
            cin >> a;
            a--;
            T[a].set(i, j, 1);
        }
    }
    for (int k = 0; k < N; k++) T[k].preprocessing();
    for (int i = 0; i + h <= H; i++) {
        for (int j = 0; j + w <= W; j++) {
            int ans = 0;
            for (int k = 0; k < N; k++) {
                if (T[k].query(0, H, 0, W) - T[k].query(i, i+h, j, j+w) > 0) ans++;
            }
            cout << ans;
            if (j+w == W) cout << "\n";
            else cout << " ";
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
