// https://atcoder.jp/contests/abc118/tasks/abc118_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    ll g;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        if (i == 0) g = a;
        else g = gcd(g, a);
    }
    cout << g << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
