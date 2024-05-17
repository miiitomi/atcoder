// https://atcoder.jp/contests/abc331/tasks/abc331_d
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

int N, Q;
ll cnt;

ll f(tdcs &t, ll i, ll j) {
    if (i < 0 || j < 0) return 0;
    ll a = (i+1) / N, b = (j+1) / N;
    i = (i+1) % N;
    j = (j+1) % N;
    ll ans = a*b*cnt;
    if (i > 0) ans += t.sum(0, 0, i-1, N-1) * b;
    if (j > 0) ans += t.sum(0, 0, N-1, j-1) * a;
    if (i > 0 && j > 0) ans += t.sum(0, 0, i-1, j-1);
    return ans;
}


void solve() {
    cin >> N >> Q;
    tdcs t(N, N);
    cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            if (c == 'B') {
                t.set(i, j, 1);
                cnt++;
            }
        }
    }
    t.preprocessing();

    while (Q--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll ans = f(t, c, d);
        ans -= f(t, a-1, d);
        ans -= f(t, c, b-1);
        ans += f(t, a-1, b-1);
        cout << ans << "\n";
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
