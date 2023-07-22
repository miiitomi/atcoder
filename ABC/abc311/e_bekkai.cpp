// ABC311 E 二次元累積和と二分探索を用いた別解法
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// two-dimensional cummurated sum
struct tdcs {
    int n;
    int w;
    vector<vector<ll>> a;
    vector<vector<ll>> s;

    tdcs(int n_, int w_) {
        n = n_;
        w = w_;
        a.assign(n, vector<ll>(w, 0));
        s.assign(n, vector<ll>(w, 0));
    }

    void set(int i, int j, int x) {
        a[i][j] = x;
    }

    void preprocessing() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < w; j++) {
                s[i][j] += a[i][j];
                if (i > 0) s[i][j] += s[i-1][j];
                if (j > 0) s[i][j] += s[i][j-1];
                if (i > 0 && j > 0) s[i][j] -= s[i-1][j-1];
            }
        }
    }

    ll sum(int i1, int j1, int i2, int j2) {
        ll ans = s[i2][j2];
        if (i1 > 0) ans -= s[i1-1][j2];
        if (j1 > 0) ans -= s[i2][j1-1];
        if (i1 > 0 && j1 > 0) ans += s[i1-1][j1-1];
        return ans;
    }
};

int main() {
    int H, W, N;
    cin >> H >> W >> N;

    tdcs t(H, W);
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
            if (t.a[i][j]) continue;
            int l = 1;
            int r = 1 + min(H-i, W-j);
            while (r - l > 1) {
                int m = (l + r) / 2;
                if (t.sum(i, j, i+m-1, j+m-1) == 0) l = m;
                else r = m;
            }
            ans += l;
        }
    }
    cout << ans << endl;
}
