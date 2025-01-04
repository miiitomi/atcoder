// https://atcoder.jp/contests/typical90/tasks/typical90_ae
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    vector<vector<ll>> dp(51, vector<ll>(1326, 0));
    for (int w = 0; w <= 50; w++) {
        for (int b = 0; b <= 1325; b++) {
            vector<bool> c(700, true);
            if (w > 0 && b+w <= 1325) c[dp[w-1][b+w]] = false;
            for (int k = 1; k <= b/2; k++) c[dp[w][b-k]] = false;
            for (int x = 0; x < 700; x++) {
                if (c[x]) {
                    dp[w][b] = x;
                    break;
                }
            }
        }
    }

    int N;
    cin >> N;
    vector<int> W(N), B(N);
    for (int i = 0; i < N; i++) cin >> W[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    int tmp = 0;
    for (int i = 0; i < N; i++) tmp ^= dp[W[i]][B[i]];

    if (tmp > 0) cout << "First\n";
    else cout << "Second\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
