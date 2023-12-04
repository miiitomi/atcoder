#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, Q;
vector<string> P;

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


ll f(ll r, ll c, tdcs &T) {
    if (r < 0 || c < 0) return 0;

    ll ans = 0;

    if (r >= N && c >= N) {
        ll s = r/N, t = c/N;
        ans += s*t*T.sum(0, 0, N-1, N-1);
    }

    if (r >= N) {
        ll s = r / N;
        ans += s*T.sum(0, 0, N-1, c%N);
    }

    if (c >= N) {
        ll t = c / N;
        ans += t*T.sum(0, 0, r%N, N-1);
    }

    ans += T.sum(0, 0, r%N, c%N);
    return ans;
}

int main() {
    cin >> N >> Q;
    P.resize(N);
    for (int i = 0; i < N; i++) cin >> P[i];

    tdcs T(N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (P[i][j] == 'B') T.set(i, j, 1);
        }
    }
    T.preprocessing();

    for (int q = 0; q < Q; q++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll tmp = f(c, d, T);
        tmp -= f(a-1, d, T);
        tmp -= f(c, b-1, T);
        tmp += f(a-1, b-1, T);
        cout << tmp << endl;
    }
}
