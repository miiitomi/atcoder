// https://atcoder.jp/contests/abc207/tasks/abc207_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;
const double eps = 1e-6;

void solve() {
    ll N;
    cin >> N;
    if (N == 1) {
        cout << "Yes\n";
        return;
    }
    vector<double> a(N), b(N), c(N), d(N);
    for (int _ = 0; _ < 2; _++) {
        double x = 0, y = 0;
        for (int i = 0; i < N; i++) {
            cin >> a[i] >> b[i];
            x += a[i];
            y += b[i];
            a[i] *= N;
            b[i] *= N;
        }
        for (int i = 0; i < N; i++) {
            a[i] -= x;
            b[i] -= y;
        }
        swap(a, c);
        swap(b, d);
    }
    if (a[0] == 0 && b[0] == 0) {
        swap(a[0], a[1]);
        swap(b[0], b[1]);
    }
    for (int i = 0; i < N; i++) {
        if (c[i] == 0 && d[i] == 0) continue;
        double theta = atan2(b[0], a[0]) - atan2(d[i], c[i]);
        bool ok = true;
        for (int j = 0; j < N; j++) {
            double x = cos(theta)*c[j] - sin(theta)*d[j];
            double y = sin(theta)*c[j] + cos(theta)*d[j];
            bool tmp = false;
            for (int k = 0; k < N; k++) {
                if (abs(x - a[k]) < eps && abs(y - b[k]) < eps) {
                    tmp = true;
                    break;
                }
            }
            ok &= tmp;
            if (!ok) break;
        }
        if (ok) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
