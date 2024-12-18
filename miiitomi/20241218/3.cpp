// https://atcoder.jp/contests/abc045/tasks/arc061_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    string S;
    cin >> S;
    int N = S.size();
    ll ans = 0;
    for (int s = 0; s < (1 << (N-1)); s++) {
        ll tmp = 0;
        for (int i = 0; i < N; i++) {
            tmp = tmp*10 + (S[i] - '0');
            if (i == N-1 || s & (1 << i)) {
                ans += tmp;
                tmp = 0;
            }
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
