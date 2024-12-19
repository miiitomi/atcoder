// https://atcoder.jp/contests/abc068/tasks/arc079_b
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
    cin >> K;
    ll N = 50;
    vector<ll> a(N, 49);
    for (int i = 0; i < N; i++) a[i] += K/N;
    K %= N;
    while (K--) {
        vector<ll> b(N);
        for (int i = 0; i < N; i++) {
            if (i == 0) {
                b[i] = a[i]+N;
            } else {
                b[i] = a[i] - 1;
            }
        }
        sort(b.begin(), b.end());
        swap(a, b);
    }
    cout << N << endl;
    for (ll x : a) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
