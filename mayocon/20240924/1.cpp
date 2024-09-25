// https://atcoder.jp/contests/abc086/tasks/abc086_b
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
    for (int i = 0; i < 2; i++) {
        string a;
        cin >> a;
        S += a;
    }
    ll N = stoll(S);

    for (ll x = 1; x*x <= N; x++) {
        if (x*x == N) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
