// https://atcoder.jp/contests/abc286/tasks/abc286_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N;
    string S;
    cin >> N >> S;
    string T;
    for (char c : S) {
        if (!T.empty() && T.back() == 'n' && c == 'a') T.push_back('y');
        T.push_back(c);
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
