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
    int K;
    cin >> H >> W >> K;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];
    vector<vector<int>> v;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '.') {
                v.push_back(vector<int>(1, to_int(i, j)));
            }
        }
    }
    while (K--) {
        vector<vector<int>> nv;
        for (auto &w : v) {
            auto [i, j] = to_xy(w.back());
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (!is_in(x, y) || S[x][y] == '#' || (find(w.begin(), w.end(), to_int(x, y)) != w.end())) continue;
                w.push_back(to_int(x, y));
                nv.push_back(w);
                w.pop_back();
            }
        }
        swap(v, nv);
    }
    cout << v.size() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
