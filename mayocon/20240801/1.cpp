// https://atcoder.jp/contests/abc220/tasks/abc220_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll K;
    string A, B;
    cin >> K >> A >> B;
    ll a = 0, b = 0;
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    ll x = 1;
    for (char c : A) {
        a += (c - '0') * x;
        x *= K;
    }
    x = 1;
    for (char c : B) {
        b += (c - '0') * x;
        x *= K;
    }
    cout << a*b << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
