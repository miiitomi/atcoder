// https://atcoder.jp/contests/abc261/tasks/abc261_b
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
    vector<string> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (A[i][j] == 'W') {
                if (A[j][i] != 'L') {
                    cout << "incorrect\n";
                    return;
                }
            } else if (A[i][j] == 'L') {
                if (A[j][i] != 'W') {
                    cout << "incorrect\n";
                    return;
                }
            } else {
                if (A[j][i] != 'D') {
                    cout << "incorrect\n";
                    return;
                }
            }
        }
    }
    cout << "correct\n";
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
