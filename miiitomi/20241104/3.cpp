// https://atcoder.jp/contests/abc069/tasks/arc080_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    vector<vector<int>> c(H, vector<int>(W, 0));
    int x = 0, y = 0;
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < a[i]; k++) {
            c[x][y] = i+1;
            if (x%2 == 0) {
                if (y+1 < W) y++;
                else x++;
            } else {
                if (y-1 >= 0) y--;
                else x++;
            }
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << c[i][j] << " ";
        }
        cout << "\n";
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
