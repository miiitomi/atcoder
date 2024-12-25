// https://atcoder.jp/contests/abc299/tasks/abc299_d
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
    int left = 1, right = N;
    while (right - left > 1) {
        int m = (left + right) / 2;
        cout << "? " << m << endl;
        int s;
        cin >> s;
        if (s == 0) left = m;
        else right = m;
    }
    cout << "! " << left << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
