#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int H, W, x, y;
    cin >> H >> W >> x >> y;
    x--; y--;
    vector<string> C(H);
    for (int i = 0; i < H; i++) cin >> C[i];
    string S;
    cin >> S;

    for (char c : S) {
        if (c == 'L') {
            if (y > 0 && C[x][y-1] == '.') y--;
        } else if (c == 'R') {
            if (y < W-1 && C[x][y+1] == '.') y++;
        } else if (c == 'U') {
            if (x > 0 && C[x-1][y] == '.') x--;
        } else {
            if (x < H-1 && C[x+1][y] == '.') x++;
        }
    }

    cout << x+1 << " " << y+1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
