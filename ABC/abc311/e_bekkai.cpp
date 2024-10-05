// ABC311 E 二次元累積和と二分探索を用いた別解法
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// two-dimensional cummurated sum
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
int main() {
    int H, W, N;
    cin >> H >> W >> N;

    TwoDimensionalCumulatedSum<int> t(H, W);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        t.set(a, b, 1);
    }
    t.preprocessing();

    ll ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (t.A[i][j]) continue;
            int l = 1;
            int r = 1 + min(H-i, W-j);
            while (r - l > 1) {
                int m = (l + r) / 2;
                if (t.query(i, i+m, j, j+m) == 0) l = m;
                else r = m;
            }
            ans += l;
        }
    }
    cout << ans << endl;
}
