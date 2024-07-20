#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll H, W;
vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
pair<int,int> to_xy(int i) {return make_pair(i/W, i%W);}

void solve() {
    ll Y;
    cin >> H >> W >> Y;
    vector<vector<ll>> A(H, vector<ll>(W));
    vector<vector<pair<ll,ll>>> B(Y+1);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
            if (A[i][j] <= Y) B[A[i][j]].push_back({i, j});
        }
    }
    vector<vector<bool>> front_sea(H, vector<bool>(W, false));
    for (int i = 0; i < H; i++) {
        front_sea[i][0] = true;
        front_sea[i][W-1] = true;
    }
    for (int j = 0; j < W; j++) {
        front_sea[0][j] = true;
        front_sea[H-1][j] = true;
    }
    vector<vector<bool>> under_sea(H, vector<bool>(W, false));
    vector<ll> cnt(Y+1, 0);

    for (int i = 1; i <= Y; i++) {
        queue<pair<int,int>> Q;
        for (auto p : B[i]) {
            under_sea[p.first][p.second] = true;
            if (front_sea[p.first][p.second]) {
                Q.push(p);
                cnt[i]++;
            }
        }

        while (!Q.empty()) {
            auto p = Q.front();
            Q.pop();
            for (int k = 0;k < 4; k++) {
                ll x = p.first+dx[k], y = p.second+dy[k];
                if (!is_in(x, y) || front_sea[x][y]) continue;
                front_sea[x][y] = true;
                if (under_sea[x][y]) {
                    cnt[i]++;
                    Q.push({x, y});
                }
            }
        }
    }

    cnt[0] = H*W;
    for (int i = 1; i <= Y; i++) {
        cnt[i] = cnt[i-1] - cnt[i];
        cout << cnt[i] << "\n";
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
