// https://atcoder.jp/contests/abc203/tasks/abc203_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

void solve() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> A[i][j];
    int m = K*K - (K*K/2);

    int left = -1, right = (int)1e+9;
    while (right - left > 1) {
        int x = (left + right) / 2;
        tdcs t(N, N);
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (A[i][j] <= x) t.set(i, j, 1);
        t.preprocessing();
        bool is_ok = false;
        for (int i = 0; i+K <= N; i++) {
            for (int j = 0; j+K <= N; j++) {
                if (t.sum(i, j, i+K-1, j+K-1) >= m) is_ok = true;
            }
        }   
        if (is_ok) right = x;
        else left = x;
    }
    cout << right << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
