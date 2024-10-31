#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    vector<string> S(8);
    for (int i = 0; i < 8; i++) cin >> S[i];

    vector<vector<int>> T(8, vector<int>(8, 0));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (S[i][j] == '.') continue;
            for (int k = 0; k < 8; k++) {
                T[i][k]++;
                T[k][j]++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) ans += (T[i][j] == 0);
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
