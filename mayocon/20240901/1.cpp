// https://atcoder.jp/contests/abc210/tasks/abc210_b
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
    cin >> N;
    string S;
    cin >> S;
    auto iter = find(S.begin(), S.end(), '1');
    if (((int)distance(S.begin(), iter) & 1) == 0) {
        cout << "Takahashi\n";
    } else {
        cout << "Aoki\n";
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
