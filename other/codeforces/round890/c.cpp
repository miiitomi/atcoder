#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    int m = -1;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        m = max(m, A[i]);
    }

    for (int i = 0; i < N-1; i++) {
        vector<int> B = A;
        int k = K;
        if (B[i] <= B[i+1]) {
            B[i] += min(k, 1+B[i+1]-B[i]);
            k -= B[i] - A[i];
        }
        m = max(m, B[i]);
        for (int j = 1; i+j < N-1; j++) {
            if (B[i+j-1]-1 > B[i+j]) {
                k -= B[i+j-1]-1 - B[i+j];
                B[i+j] = B[i+j-1] - 1;
            }
            if (k <= j) break;
            int x = max(B[i+j], B[i+j+1]+1) - B[i+j];
            int y = min(x, k/(1+j));
            k -= (1+j)*y;
            B[i] += y;
            B[i+j] += y;
            m = max(m, B[i]);
        }
    }

    cout << m << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
