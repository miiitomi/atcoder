#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N), B(N), C(N), D(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    for (int i = 0; i < N; i++) cin >> C[i];
    for (int i = 0; i < N; i++) cin >> D[i];

    int M = N * N;
    vector<int> X(M), Y(M);

    int count = 0;
    for (int a : A) {
        for (int b : B) {
            X[count] = a + b;
            count++;
        }
    }

    count = 0;
    for (int c : C) {
        for (int d : D) {
            Y[count] = c + d;
            count++;
        }
    }

    sort(Y.begin(), Y.end());
    for (int x : X) {
        int y = *lower_bound(Y.begin(), Y.end(), K - x);
        if (x + y == K) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}
