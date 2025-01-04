// https://atcoder.jp/contests/typical90/tasks/typical90_al
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll A, B;
    cin >> A >> B;
    ll g = gcd(A, B);
    ll r = B/g;
    if (A > ((ll)1e+18)/r) cout <<  "Large\n";
    else cout << A*r << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
