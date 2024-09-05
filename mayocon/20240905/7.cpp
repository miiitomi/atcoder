// https://atcoder.jp/contests/abc312/tasks/abc312_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<int> dx{1, -1, 0, 0, 0, 0}, dy{0, 0, 1, -1, 0, 0}, dz{0, 0, 0, 0, 1, -1};

void solve() {
    int N;
    cin >> N;
    vector<vector<vector<int>>> X(100, vector<vector<int>>(100, vector<int>(100, -1)));
    for (int i = 0; i < N; i++) {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for (int a = x1; a < x2; a++) {
            for (int b = y1; b < y2; b++) {
                for (int c = z1; c < z2; c++) {
                    X[a][b][c] = i;
                }
            }
        }
    }
    vector<set<int>> st(N);
    for (int x = 0; x < 100; x++) {
        for (int y = 0; y < 100; y++) {
            for (int z = 0; z < 100; z++) {
                int i = X[x][y][z];
                if (i == -1) continue;
                for (int k = 0; k < 6; k++) {
                    int a = x+dx[k], b = y+dy[k], c = z + dz[k];
                    if (a < 0 || 100 <= a || b < 0 || 100 <= b || c < 0 || 100 <= c) continue;
                    int j = X[a][b][c];
                    if (j == -1 || i == j) continue;
                    st[i].insert(j);
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << st[i].size() << endl;
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
