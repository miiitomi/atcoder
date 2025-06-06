// https://atcoder.jp/contests/abc285/tasks/abc285_b
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
    for (int i = 1; i < N; i++) {
        int l = 0;
        for (int k = 0; k+i < N; k++) {
            if (S[k] != S[k+i]) l++;
            else break;
        }
        cout << l << "\n";
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
