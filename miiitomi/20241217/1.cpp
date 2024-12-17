// https://atcoder.jp/contests/abc115/tasks/abc115_b
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
    ll sum = 0, m = -1;
    for (int i = 0; i < N; i++) {
        ll p;
        cin >> p;
        sum += p;
        m = max(m, p);
    }
    sum -= m/2;
    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
