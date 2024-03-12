// https://atcoder.jp/contests/abc133/tasks/abc133_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i % 2 == 0) B[0] += A[i];
        else B[0] -= A[i];
    }
    cout << B[0] << " ";
    for (int i = 1; i < N; i++) {
        B[i] = 2 * A[i-1] - B[i-1];
        cout << B[i];
        if (i == N-1) cout << endl;
        else cout << " ";
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
