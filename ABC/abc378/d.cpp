#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

int H, W, K, ans = 0;
vector<string> S;
vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
pair<int,int> to_xy(int i) {return make_pair(i/W, i%W);}

void dfs(int i, int j, int k, vector<vector<bool>> &reached) {
    if (k == K) {
        ans++;
        return;
    }
    for (int l = 0; l < 4; l++) {
        int x = i + dx[l], y = j + dy[l];
        if (!is_in(x, y) || reached[x][y] || S[x][y]=='#') continue;
        reached[x][y] = true;
        dfs(x, y, k+1, reached);
        reached[x][y] = false;
    }
}

void solve() {
    cin >> H >> W >> K;
    S.resize(H);
    for (string &s : S) cin >> s;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') continue;
            vector<vector<bool>> reached(H, vector<bool>(W, false));
            reached[i][j] = true;
            dfs(i, j, 0, reached);
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
