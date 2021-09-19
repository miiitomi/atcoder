#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N), T(Q), x(Q), y(Q);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < Q; i++) cin >> T[i] >> x[i] >> y[i];

    int top = 0;
    for (int i = 0; i < Q; i++) {
        if (T[i] == 1) {
            swap(A[(top + x[i] - 1)%N], A[(top + y[i] - 1)%N]);
        } else if (T[i] == 2) {
            top--;
            if (top == -1) top = N-1;
        } else {
            cout << A[(top + x[i] - 1) % N] << endl;
        }
    }
}
