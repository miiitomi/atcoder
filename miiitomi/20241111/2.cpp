// https://atcoder.jp/contests/abc258/tasks/abc258_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    ll tmp = 0;
    while (Q--) {
        ll k, x;
        cin >> k >> x;
        if (k == 1) {
            tmp = (tmp - x + N) % N;
        } else {
            x--;
            cout << S[(tmp + x) % N] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
