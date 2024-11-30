// https://atcoder.jp/contests/abc093/tasks/abc093_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll a, b, k;
    cin >> a >> b >> k;
    set<ll> st;
    for (int x = a; x <= min(b, a+k-1); x++) st.insert(x);
    for (int y = b; y >= max(a, b-k+1); y--) st.insert(y);
    for (ll a : st) cout << a << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
