// https://atcoder.jp/contests/abc127/tasks/abc127_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N+2, 0);
    for (int i = 0; i < M; i++) {
        int l, r;
        cin >> l >> r;
        A[l]++;
        A[r+1]--;
    }
    int ans = 0;
    for (int i = 0; i <= N; i++) {
        A[i+1] += A[i];
        if (A[i] == M) ans++;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
