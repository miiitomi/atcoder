// https://atcoder.jp/contests/abc257/tasks/abc257_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N, X;
    cin >> N >> X;
    string S;
    for (char c = 'A'; c <= 'Z'; c++) {
        for (int k = 0; k < N; k++) S.push_back(c);
    }
    cout << S[X-1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
