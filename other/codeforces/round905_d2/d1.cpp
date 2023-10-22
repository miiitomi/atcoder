#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(N);
    A[0] = 1;
    for (int i = 1; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int ans = 0;
    int cur = 0;

    while (ans + cur < N) {
        while (A[cur] >= B[ans+cur] && ans + cur < N) {
            ans++;
        }
        cur++;
    }

    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
