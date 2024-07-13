// https://atcoder.jp/contests/abc113/tasks/abc113_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, T, A;
    cin >> N >> T >> A;
    A *= 1000;

    ll mv = INF;
    ll ans = -1;
    for (int i = 1; i <= N; i++) {
        ll h;
        cin >> h;
        ll B = 1000*T - h*6;
        if (abs(A-B) < mv) {
            mv = abs(A-B);
            ans = i;
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
