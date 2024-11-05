// https://atcoder.jp/contests/abc048/tasks/arc064_b
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
    if (S.front() == S.back()) {
        if ((int)S.size()%2 == 0) cout << "First\n";
        else cout << "Second\n";
    } else {
        if ((int)S.size()%2 == 0) cout << "Second\n";
        else cout << "First\n";
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
