#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int ans = 0;
    int tmp = 0;
    for (int i = 0; i < N; i++) {
        if (tmp + A[i] > K) {
            tmp = 0;
            ans++;
        }
        tmp += A[i];
    }
    ans++;
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
