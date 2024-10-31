// https://atcoder.jp/contests/abc198/tasks/abc198_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

bool is_kaibun(string S) {
    string T = S;
    reverse(T.begin(), T.end());
    return T == S;
}

void solve() {
    string N;
    cin >> N;
    reverse(N.begin(), N.end());

    for (int i = 0; i < 20; i++) {
        if (is_kaibun(N)) {
            cout << "Yes\n";
            return;
        }
        N.push_back('0');
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
