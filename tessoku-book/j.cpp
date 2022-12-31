#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<int> L(N, 0), R(N, 0);
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            L[0] = A[0];
        } else {
            L[i] = max(L[i-1], A[i]);
        }
    }
    for (int i = N-1; i >= 0; i--) {
        if (i == N-1) {
            R[i] = A[i];
        } else {
            R[i] = max(R[i+1], A[i]);
        }
    }

    int D;
    cin >> D;
    for (int i = 0; i < D; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int ans = 0;
        if (l > 0) {
            ans = max(ans, L[l-1]);
        }
        if (r < N-1) {
            ans = max(ans, R[r+1]);
        }
        cout << ans << endl;
    }
}
