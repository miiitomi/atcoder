// https://atcoder.jp/contests/abc045/tasks/abc045_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    vector<string> S(3);
    for (string &s : S) {
        cin >> s;
        reverse(s.begin(), s.end());
    }
    int tmp = 0;
    while (true) {
        if (S[tmp].empty()) {
            cout << (char)('A' + tmp) << endl;
            return;
        }
        char c = S[tmp].back();
        S[tmp].pop_back();
        tmp = c - 'a';
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
