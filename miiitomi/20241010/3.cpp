// https://atcoder.jp/contests/abc051/tasks/abc051_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int x = sx, y = sy;
    string S = "";
    S += string(tx - sx, 'R');
    S += string(ty - sy, 'U');
    S += string(tx - sx, 'L');
    S += string(ty - sy, 'D');
    S.push_back('D');
    S += string(tx - sx + 1, 'R');
    S += string(ty - sy + 1, 'U');
    S.push_back('L');
    S.push_back('U');
    S += string(tx-sx+1, 'L');
    S += string(ty - sy + 1, 'D');
    S.push_back('R');
    cout << S << endl;

    // for (char c : S) {
    //     if (c == 'R') x++;
    //     else if (c == 'U') y++;
    //     else if (c == 'L') x--;
    //     else y--;
    //     cerr << x << " " << y << endl;
    // }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
