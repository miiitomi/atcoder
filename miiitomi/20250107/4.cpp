// https://atcoder.jp/contests/abc105/tasks/abc105_c
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
    if (N == 0) {
        cout << 0 << endl;
        return;
    }
    string S = "";
    ll x = 2;
    bool pos = true;
    while (N != 0) {
        if (N % x == 0) {
            S.push_back('0');
        } else {
            S.push_back('1');
            if (pos) N -= x/2;
            else N += x/2;
        }
        pos ^= true;
        x *= 2;
    }
    reverse(S.begin(), S.end());
    cout << S << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
