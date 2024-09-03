// https://atcoder.jp/contests/abc213/tasks/abc213_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

int H, W;
vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
pair<int,int> to_xy(int i) {return make_pair(i/W, i%W);}

void solve() {
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];
    vector<vector<ll>> d(H, vector<ll>(W, INF));
    d[0][0] = 0;
    deque<pair<ll,ll>> Q;
    Q.push_back({0, 0});
    while (!Q.empty()) {
        auto [x, y] = Q.front();
        Q.pop_front();

        for (int k = 0; k < 4; k++) {
            int a = x + dx[k], b = y + dy[k];
            if (!is_in(a, b) || S[a][b] != '.' || d[a][b] <= d[x][y]) continue;
            d[a][b] = d[x][y];
            Q.push_front({a, b});
        }

        for (int i = -2; i <= 2; i++) {
            for (int j = -2; j <= 2; j++) {
                if (abs(i) == 2 && abs(j) == 2) continue;
                int a = x + i, b = y + j;
                if (!is_in(a, b) || d[a][b] <= d[x][y] + 1) continue;
                d[a][b] = d[x][y] + 1;
                Q.push_back({a, b});
            }
        }
    }

    cout << d[H-1][W-1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
