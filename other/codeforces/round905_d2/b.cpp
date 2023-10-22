#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    if (K != 4) {
        int x = 1e+9;
        for (int i = 0; i < N; i++) {
            if (A[i] % K == 0) x = 0;
            else x = min(x, K - (A[i] % K));
        }
        cout << x << endl;
        return;
    }

    int two = 0, four = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] % 2 == 0) two++;
        if (A[i] % 4 == 0) four++;
    }

    if (two >= 2 || four >= 1) {
        cout << 0 << endl;
        return;
    }

    int x = 2 - two;
    for (int i = 0; i < N; i++) {
        x = min(x, K - (A[i] % 4));
    }
    cout << x << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
