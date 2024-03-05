// https://atcoder.jp/contests/abc140/tasks/abc140_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N), B(N-1);
    for (int i = 0; i < N-1; i++) cin >> B[i];
    A[0] = B[0];
    A[N-1] = B[N-2];
    int ans = A[0] + A[N-1];
    for (int i = 1; i < N-1; i++) {
        A[i] = min(B[i-1], B[i]);
        ans += A[i];
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
