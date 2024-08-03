// https://atcoder.jp/contests/abc311/tasks/abc311_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    vector<ll> dx{0, 0, 1, -1}, dy{1, -1, 0, 0};
    queue<pair<int,int>> Q;
    vector<vector<bool>> stopped(N, vector<bool>(M, false)), through(N, vector<bool>(M, false));
    stopped[1][1] = true;
    through[1][1] = true;
    Q.push({1, 1});
    while (!Q.empty()) {
        auto [x, y] = Q.front();
        Q.pop();
        for (int k = 0; k < 4; k++) {
            int p = x, q = y;
            while (S[p+dx[k]][q+dy[k]] == '.') {
                p += dx[k];
                q += dy[k];
                through[p][q] = true;
            }
            if (!stopped[p][q]) {
                stopped[p][q] = true;
                Q.push({p, q});
            }
        }
    }
    ll ans = 0;
    for (int x = 0; x < N; x++) for (int y = 0; y < M; y++) ans += through[x][y];
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
