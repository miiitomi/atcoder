#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

int H, W;
vector<int> dx{0, 1, 0, -1}, dy{1, 0, -1, 0};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
pair<int,int> to_xy(int i) {return make_pair(i/W, i%W);}

void solve() {
    cin >> H >> W;
    vector<string> S(H);
    queue<pair<int,int>> Q;
    for (int i = 0; i < H; i++) {
        cin >> S[i];
        for (int j = 0; j < W; j++) {
            if (S[i][j] == 'E') {
                Q.push({i, j});
            }
        }
    }

    while (!Q.empty()) {
        int x = Q.front().first, y = Q.front().second;
        Q.pop();

        for (int k = 0; k < 4; k++) {
            int a = x + dx[k], b = y + dy[k];
            if (!is_in(a, b) || S[a][b] != '.') continue;
            if (k == 0) S[a][b] = '<';
            else if (k == 2) S[a][b] = '>';
            else if (k == 1) S[a][b] = '^';
            else S[a][b] = 'v';

            Q.push({a, b});
        }
    }

    for (auto &s : S) cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
