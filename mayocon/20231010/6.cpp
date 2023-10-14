// https://atcoder.jp/contests/abc178/tasks/abc178_f
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N+1, 0), D(N+1, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        C[A[i]]++;
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
        D[B[i]]++;
    }

    for (int i = 1; i <= N; i++) {
        if (C[i] + D[i] > N) {
            cout << "No" << endl;
            return 0;
        }
        C[i] += C[i-1];
        D[i] += D[i-1];
    }

    int x = -1;
    for (int i = 1; i <= N; i++) x = max(x, C[i] - D[i-1]);

    vector<int> X(N);
    for (int i = 0; i < N; i++) X[(i+x)%N] = B[i];

    cout << "Yes" << endl;
    for (int v : X) cout << v << " ";
    cout << endl;
}
