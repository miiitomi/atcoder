// 小課題1, 2用

#include <bits/stdc++.h>
using namespace std;

int main() {
    int W, N;
    cin >> W >> N;
    vector<int> A(W, 0), B(N);
    for (int i = 0; i < N; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int m = 0;
        for (int i = l; i < r + 1; i++) {
            if (m < A[i]) m = A[i];
        }
        for (int i = l; i < r + 1; i++) {
            A[i] = m + 1;
        }
        B[i] = m + 1;
    }

    for (int i = 0; i < N; i++) {
        cout << B[i] << endl;
    }
}
