// https://atcoder.jp/contests/abc068/tasks/abc068_b
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
    int ans = -1, cnt = -1;
    for (int x = 1; x <= N; x++) {
        int tmp = 0, y = x;
        while (y % 2 == 0) {
            tmp++;
            y /= 2;
        }
        if (cnt < tmp) {
            cnt = tmp;
            ans = x;
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
