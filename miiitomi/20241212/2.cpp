// https://atcoder.jp/contests/abc043/tasks/abc043_b
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
    string T = "";
    for (char c : S) {
        if (c == 'B') {
            if (!T.empty()) {
                T.pop_back();
            }
        } else {
            T.push_back(c);
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
