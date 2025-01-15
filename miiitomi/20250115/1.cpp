// https://atcoder.jp/contests/abc226/tasks/abc226_a
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
    cin >> S;
    int N = 0;
    reverse(S.begin(), S.end());
    while (S.back() != '.') {
        N = 10*N + (S.back() - '0');
        S.pop_back();
    }
    S.pop_back();
    if (S.back() >= '5') N++;
    cout << N << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
