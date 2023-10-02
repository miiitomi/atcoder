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
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<vector<ll>> A(N, vector<ll>(N, 0));
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        A[a][b]++;
    }

    tdcs T(N, N);
    T.a = A;
    T.preprocessing();

    for (int q = 0; q < Q; q++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        cout << T.sum(x, x, y, y) << endl;
    }
}
