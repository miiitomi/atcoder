#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    string S;
    cin >> S;
    int x0 = 0, x1 = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '0') x0 ^= A[i];
        else x1 ^= A[i];
    }
    vector<int> C(N+1, 0);
    for (int i = 0; i < N; i++) C[i+1] = C[i]^A[i];

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            x0 ^= C[r+1]^C[l];
            x1 ^= C[r+1]^C[l];
        } else {
            int k;
            cin >> k;
            if (k == 0) cout << x0 << " ";
            else cout << x1 << " ";
        }
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
