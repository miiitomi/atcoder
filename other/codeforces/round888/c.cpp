#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    if (A[0] == A[N-1]) {
        int count = 0;
        for (int a : A) {
            if (a == A[0]) count++;
        }
        if (count >= K) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return;
    }

    int x = 1e+9;
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == A[0]) count++;
        if (count == K) {
            x = i;
            break;
        }
    }
    int y = -1;
    count = 0;
    for (int i = N-1; i >= 0; i--) {
        if (A[i] == A[N-1]) count++;
        if (count == K) {
            y = i;
            break;
        }
    }
    if (x < y) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }
}
