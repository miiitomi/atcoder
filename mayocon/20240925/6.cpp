// https://atcoder.jp/contests/abc301/tasks/abc301_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const int INF = 1e+9;
const ll MOD = 998244353;

int H, W, T, N;
vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
pair<int,int> to_xy(int i) {return make_pair(i/W, i%W);}
vector<string> A;
vector<vector<int>> G;

vector<int> compute_dist(int s) {
    vector<int> d(N, INF);
    d[s] = 0;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v : G[u]) {
            if (d[v] != INF) continue;
            d[v] = d[u] + 1;
            Q.push(v);
        }
    }
    return d;
}

void solve() {
    cin >> H >> W >> T;
    N = H*W;
    A.resize(H);
    G.resize(N);
    for (int i = 0; i < H; i++) cin >> A[i];
    vector<pair<int,int>> v;
    pair<int,int> s, g;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] == '#') continue;
            if (A[i][j] != '.') v.push_back({i, j});
            if (A[i][j] == 'S') s = {i, j};
            if (A[i][j] == 'G') g = {i, j};
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (!is_in(x, y) || A[x][y] == '#') continue;
                G[to_int(i, j)].push_back(to_int(x, y));
            }
        }
    }
    vector<vector<int>> d(v.size(), vector<int>(v.size(), INF));
    for (int i = 0; i < (int)v.size(); i++) {
        vector<int> tmp = compute_dist(to_int(v[i].first, v[i].second));
        for (int j = 0; j < (int)v.size(); j++) {
            d[i][j] = min(d[i][j], tmp[to_int(v[j].first, v[j].second)]);
        }
    }

    vector<vector<ll>> dp(1 << (int)v.size(), vector<ll>(v.size(), INF));
    for (int i = 0; i < (int)v.size(); i++) {
        if (v[i] == s) dp[1 << i][i] = 0;
    }
    for (int s = 1; s < (1 << (int)v.size()); s++) {
        for (int i = 0; i < (int)v.size(); i++) {
            if (!(s & (1 << i))) continue;
            for (int j = 0; j < (int)v.size(); j++) {
                if (s & (1 << j)) continue;
                dp[s | (1 << j)][j] = min(dp[s | (1 << j)][j], dp[s][i] + d[i][j]);
            }
        }
    }
    ll ans = -1;
    int G = distance(v.begin(), find(v.begin(), v.end(), g));
    for (int st = 1; st < (1 << (int)v.size()); st++) {
        if (dp[st][G] <= T) {
            ll cnt = 0;
            for (int i = 0; i < (int)v.size(); i++) {
                if (v[i] == s || v[i] == g) continue;
                if (st & (1 << i)) cnt++;
            }
            ans = max(ans, cnt);
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
