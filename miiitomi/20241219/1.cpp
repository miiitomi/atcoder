// https://atcoder.jp/contests/abc088/tasks/abc088_a
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N, A;
    cin >> N >> A;
    while (N >= 500) {
        N -= 500;
    }
    if (N <= A) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
