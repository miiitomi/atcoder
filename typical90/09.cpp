// https://atcoder.jp/contests/typical90/tasks/typical90_i
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<ll> X(N), Y(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
    double ans = -1;
    for (int i = 0; i < N; i++) {
        vector<double> v;
        for (int j = 0; j < N; j++) {
            if (j == i) continue;
            double theta = atan2(Y[j]-Y[i]+0.0, X[j]-X[i]+0.0);
            v.push_back(theta);
            v.push_back(theta + 2.0*M_PI);
        }
        sort(v.begin(), v.end());
        int r = -1;
        for (int l = 0; l < N-1; l++) {
            while (v[r+1]-v[l] <= M_PI) r++;
            ans = max(ans, 180.0*(v[r]-v[l])/M_PI);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
