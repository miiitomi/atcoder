// https://atcoder.jp/contests/abc211/tasks/abc211_e
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
    ll N, K;
    cin >> N >> K;
    H = N; W = N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    vector<vector<string>> V;
    V.push_back(S);
    for (int k = 0; k < K; k++) {
        vector<vector<string>> NV;
        for (auto &T : V) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (T[i][j] != '.') continue;
                    bool is_ok = (k == 0);
                    for (int d = 0; d < 4 && !is_ok; d++) {
                        int x = i + dx[d], y = j + dy[d];
                        if (is_in(x, y) && T[x][y] == '@') is_ok = true;
                    }
                    if (is_ok) {
                        vector<string> U = T;
                        U[i][j] ='@';
                        NV.push_back(U);
                    }
                }
            }
        }
        swap(V, NV);
        sort(V.begin(), V.end());
        V.erase(unique(V.begin(), V.end()), V.end());
    }
    cout << (int)V.size() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
