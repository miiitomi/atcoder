// https://atcoder.jp/contests/abc368/tasks/abc368_c
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
    ll T = 0;
    for (int i = 0; i < N; i++) {
        ll h;
        cin >> h;
        T += 3*(h/5);
        h %= 5;
        while (h > 0) {
            T++;
            if (T%3 == 0) h -= 3;
            else h--;
        }
    }
    cout << T << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
