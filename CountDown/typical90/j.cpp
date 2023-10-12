#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N+1, 0), B(N+1, 0);
    for (int i = 0; i < N; i++) {
        int c, p;
        cin >> c >> p;
        if (c == 1) A[i+1] = p;
        else B[i+1] = p;
    }
    for (int i = 1; i <= N; i++) {
        A[i] += A[i-1];
        B[i] += B[i-1];
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        cout << A[r] - A[l] << " " << B[r] - B[l] << endl;
    }
}
