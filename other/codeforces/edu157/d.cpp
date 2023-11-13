#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N-1);
    for (int i = 0; i < N-1; i++) cin >> A[i];

    vector<int> c(20, 0);
    for (int x = 0; x <= N-1; x++) {
        for (int i = 0; i < 20; i++) if (x & (1 << i)) c[i]++;
    }

    vector<int> B(N, 0);
    for (int k = 19; k >= 0; k--) {
        bool ok = true;
        int cnt = 0;
        for (int i = 0; i < N-1; i++) {
            if (A[i] & (1 << k)) {
                if (!(B[i] & (1 << k))) {
                    cnt++;
                    B[i+1] += (1 << k);
                    if (B[i+1] >= N) {
                        ok = false;
                    }
                }
            } else {
                if (B[i] & (1 << k)) {
                    cnt++;
                    B[i+1] += (1 << k);
                    if (B[i+1] >= N) {
                        ok = false;
                    }
                }
            }
        }
        if (cnt != c[k] || !ok) {
            for (int i = 0; i < N; i++) {
                B[i] ^= (1 << k);
            }
        }
    }

    for (int b : B) cout << b << " ";
    cout << endl;
}
