// https://atcoder.jp/contests/abc299/tasks/abc299_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int o = 0, x = 0;
    for (char s : S) {
        if (s == 'o') o++;
        else x++;
    }

    if (o == 0 || x == 0) {
        cout << -1 << endl;
        return;
    }

    int ans = 0, tmp = 0;
    for (char c : S) {
        if (c == 'o') tmp++;
        else {
            ans = max(tmp, ans);
            tmp = 0;
        }
    }
    ans = max(tmp, ans);

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
