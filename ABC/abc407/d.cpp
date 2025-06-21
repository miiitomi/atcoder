#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int H, W;
    cin >> H >> W;
    vector<vector<ll>> A(H, vector<ll>(W));
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) cin >> A[i][j];
    vector<vector<vector<bool>>> B(1, vector<vector<bool>>(H, vector<bool>(W, true)));
    ll ans = -1;
    while (!B.empty()) {
        sort(B.begin(), B.end());
        B.erase(unique(B.begin(), B.end()), B.end());
        vector<vector<vector<bool>>> NB;
        for (auto &b: B) {
            ll tmp = 0;
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    if (b[i][j]) tmp ^= A[i][j];
                }
            }
            ans = max(ans, tmp);

            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    if (i+1 < H && b[i][j] && b[i+1][j]) {
                        auto c = b;
                        c[i][j] = false;
                        c[i+1][j] = false;
                        NB.push_back(c);
                    }
                    if (j+1 < W && b[i][j] && b[i][j+1]) {
                        auto c = b;
                        c[i][j] = false;
                        c[i][j+1] = false;
                        NB.push_back(c);
                    }
                }
            }
        }
        swap(B, NB);
    }
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
