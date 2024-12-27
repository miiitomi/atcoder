// https://atcoder.jp/contests/abc092/tasks/arc093_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int A, B;
    cin >> A >> B;
    vector<string> S(50, string(100, '.'));
    for (int i = 0; i < 50; i++) S.push_back(string(100, '#'));
    A--; B--;
    for (int i = 0; i < 50; i += 2) {
        for (int j = 0; j < 100; j += 2) {
            if (B == 0) break;
            S[i][j] = '#';
            B--;
        }
    }
    for (int i = 99; i >= 0; i -= 2) {
        for (int j = 0; j < 100; j += 2) {
            if (A == 0) break;
            S[i][j] = '.';
            A--;
        }
    }

    cout << 100 << " " << 100 << "\n";
    for (string s : S) {
        cout << s << "\n";
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
