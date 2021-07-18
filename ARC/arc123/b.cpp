#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    for (int i = 0; i < N; i++) cin >> C[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    vector<bool> B_use(N, false);

    int a_index = 0;
    int b_index = 0;
    while (a_index < N && b_index < N) {
        if (A[a_index] < B[b_index]) {
            B_use[b_index] = true;
            a_index++;
            b_index++;
        } else {
            b_index++;
        }
    }

    b_index = 0;
    int c_index = 0;
    while (b_index < N && c_index < N) {
        if (!B_use[b_index]) {
            b_index++;
        } else if (B[b_index] < C[c_index]) {
            b_index++;
            c_index++;
        } else {
            c_index++;
        }
    }

    int ans = 0;

    for (int i = 0; i < b_index; i++) {
        if (B_use[i]) ans++;
    }

    cout << ans << endl;
}
