// https://atcoder.jp/contests/abc245/tasks/abc245_d
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N+1, 0), B(M+1, 0), C(N+M+1, 0);
    for (int i = 0; i <= N; i++) cin >> A[i];
    for (int i = 0; i <= N+M; i++) cin >> C[i];

    for (int j = M; j >= 0; j--) {
        B[j] = C[N+j]/A[N];
        for (int k = N; k >= 0; k--) {
            C[j+k] -= B[j]*A[k];
        }
    }
    for (int b : B) cout << b << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
