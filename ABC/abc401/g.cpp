#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + 0.0);
}

void solve() {
    ll N;
    cin >> N;
    vector<double> sx(N), sy(N), gx(N), gy(N);
    for (int i = 0; i < N; i++) cin >> sx[i] >> sy[i];
    for (int i = 0; i < N; i++) cin >> gx[i] >> gy[i];

    double left = 0.0, right = 2e+18, mid;
    for (ll k = 0; k < 100; k++) {
        mid = (left + right) / 2.0;
        mf_graph<int> G(2*N+2);
        int s = 2*N, t = 2*N+1;
        for (int i = 0; i < N; i++) {
            G.add_edge(s, 2*i, 1);
            G.add_edge(2*i+1, t, 1);
            for (int j = 0; j < N; j++) {
                double d = dist(sx[i], sy[i], gx[j], gy[j]);
                if (d <= mid) {
                    G.add_edge(2*i, 2*j+1, 1);
                }
            }
        }

        int tmp = G.flow(s, t);
        if (tmp == N) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << mid << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
