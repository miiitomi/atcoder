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
    ll tmp = 0;
    ll t = 0;
    for (int i = 0; i < N; i++) {
        ll T, V;
        cin >> T >> V;
        tmp = max(0LL, tmp - (T - t)) + V;
        t = T;
    }
    cout << tmp << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
