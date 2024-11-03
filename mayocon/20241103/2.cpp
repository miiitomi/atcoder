// https://atcoder.jp/contests/abc058/tasks/abc058_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    string O, E;
    cin >> O >> E;
    string S;
    for (int i = 0; i < (int)O.size(); i++) {
        S.push_back(O[i]);
        if (i < (int)E.size()) S.push_back(E[i]);
    }
    cout << S << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
