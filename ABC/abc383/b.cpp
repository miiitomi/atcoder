#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll H, W, D;
    cin >> H >> W >> D;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];
    ll ans = -1;
    vector<pair<ll,ll>> M;
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) if (S[i][j] == '.') M.push_back({i, j});
    for (int i = 0; i < (int)M.size(); i++) {
        for (int j = i+1; j < (int)M.size(); j++) {
            auto p = M[i], q = M[j];
            ll tmp = 0;
            for (auto r : M) {
                if (min(abs(p.first-r.first)+abs(p.second-r.second), abs(q.first-r.first)+abs(q.second-r.second)) <= D) {
                    tmp++;
                }
            }
            ans = max(ans, tmp);
        }
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
