// https://atcoder.jp/contests/abc140/tasks/abc140_b
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N-1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }
    for (int i = 0; i < N; i++) cin >> B[i];
    for (int i = 0; i < N-1; i++) cin >> C[i];

    int ans = 0;
    for (int a : A) ans += B[a];
    for (int i = 0; i+1 < N; i++) {
        if (A[i]+1 == A[i+1]) {
            ans += C[A[i]];
        }
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
