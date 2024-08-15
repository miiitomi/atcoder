// https://atcoder.jp/contests/abc279/tasks/abc279_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll H, W;
    cin >> H >> W;
    vector<string> S(W, string(H, '.')), T(W, string(H, '.'));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c;
            cin >> c;
            S[j][i] = c;
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c;
            cin >> c;
            T[j][i] = c;
        }
    }
    sort(S.begin(), S.end());
    sort(T.begin(), T.end());
    if (S == T) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
