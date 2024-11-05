// https://atcoder.jp/contests/abc274/tasks/abc274_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

bool f(int x, vector<int> &X) {
    int m = (int)1e+4;
    vector<bool> dp(2*m+1, false);
    dp[m] = true;
    for (int z : X) {
        vector<bool> ndp(2*m+1, false);
        for (int a = 0; a <= 2*m; a++) {
            if (!dp[a]) continue;
            ndp[a+z] = true;
            ndp[a-z] = true;
        }
        swap(dp, ndp);
    }
    return dp[m+x];
}

void solve() {
    int N, x, y;
    cin >> N >> x >> y;
    vector<int> Y, X;
    for (int i = 0; i < N; i++) {
        int z;
        cin >> z;
        if (i == 0) {
            x -= z;
        } else if (i % 2 == 1) {
            Y.push_back(z);
        } else {
            X.push_back(z);
        }
    }
    if (f(x, X) && f(y, Y)) cout << "Yes\n";
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
