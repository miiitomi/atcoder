#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N;
    cin >> N;
    vector<int> P(N), R(N, -1);
    for (int i = 0; i < N; i++) cin >> P[i];
    int r = 1;
    while (r <= N) {
        int ma = -1;
        for (int i = 0; i < N; i++) {
            if (R[i] != -1) continue;
            ma = max(ma, P[i]);
        }
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (P[i] == ma) {
                cnt++;
                R[i] = r;
            }
        }
        r += cnt;
    }
    for (int i = 0; i < N; i++) {
        cout << R[i] << "\n";
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
