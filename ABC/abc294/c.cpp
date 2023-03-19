#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M), C(N+M);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        C[i] = A[i];
    }
    for (int j = 0; j < M; j++) {
        cin >> B[j];
        C[N+j] = B[j];
    }
    sort(C.begin(), C.end());

    for (int i = 0; i < N; i++) {
        int a = A[i];
        auto iter = lower_bound(C.begin(), C.end(), a);
        cout << 1 + (int)distance(C.begin(), iter);
        if (i == N-1) cout << endl;
        else cout << " ";
    }
    for (int i = 0; i < M; i++) {
        int b = B[i];
        auto iter = lower_bound(C.begin(), C.end(), b);
        cout << 1 + (int)distance(C.begin(), iter);
        if (i == M-1) cout << endl;
        else cout << " ";
    }
}
