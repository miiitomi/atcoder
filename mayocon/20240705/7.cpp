// https://atcoder.jp/contests/abc130/tasks/abc130_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N;
vector<ll> x, y, dx, dy;

vector<double> f(vector<ll> &v, vector<ll> &dv, ll b) {
    ll p = (2*b-1)*INF, m = (2*b-1)*INF, c = (2*b-1)*INF;
    for (int i = 0; i < N; i++) {
        if (dv[i] == 1) {
            if (b == 1) p = min(p, v[i]);
            else p = max(p, v[i]);
        } if (dv[i] == -1) {
            if (b == 1) m = min(m, v[i]);
            else m = max(m, v[i]);
        } if (dv[i] == 0) {
            if (b == 1) c = min(c, v[i]);
            else c = max(c, v[i]);
        };
    }
    vector<double> ans;
    ans.push_back(0.0);
    if (p != (2*b-1)*INF && c != (2*b-1)*INF) ans.push_back(max(0LL, c - p));
    if (p != (2*b-1)*INF && m != (2*b-1)*INF) ans.push_back(max(0.0, (m-p)/2.0));
    if (c != (2*b-1)*INF && m != (2*b-1)*INF) ans.push_back(max(0LL, m-c));
    return ans;
}

double g(double t) {
    double max_x = -INF, min_x = INF, max_y = -INF, min_y = INF;
    for (int i = 0; i < N; i++) {
        double tmp_x = x[i] + t*dx[i], tmp_y = y[i] + t*dy[i];
        max_x = max(max_x, tmp_x);
        min_x = min(min_x, tmp_x);
        max_y = max(max_y, tmp_y);
        min_y = min(min_y, tmp_y);
    }
    return (max_x-min_x)*(max_y-min_y);
}


void solve() {
    cin >> N;
    x.resize(N);
    y.resize(N);
    dx.resize(N);
    dy.resize(N);
    for (int i = 0; i < N; i++) {
        char d;
        cin >> x[i] >> y[i] >> d;
        if (d == 'R') dx[i] = 1;
        else if (d == 'L') dx[i] = -1;
        else if (d == 'U') dy[i] = 1;
        else if (d == 'D') dy[i] = -1;
    }

    vector<double> T;
    for (ll b = 0; b <= 1; b++) {
        vector<double> TT = f(x, dx, b);
        for (double t : TT) T.push_back(t);
        TT = f(y, dy, b);
        for (double t : TT) T.push_back(t);
    }
    sort(T.begin(), T.end());
    T.erase(unique(T.begin(), T.end()), T.end());

    double ans = INF;
    for (double t : T) ans = min(ans, g(t));
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
