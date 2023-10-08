#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> V(501);
    V[1] = {1};

    for (int N = 3; N <= 500; N++) {
        bool ok = true;
        for (int k = 1; k <= N-1; k++) {
            if (k*(k+1) == N) ok = false;
        }

        if (ok) {
            V[N].resize(N);
            for (int k = 1; k <= N-1; k++) {
                V[N][k-1] = k*(k+1);
            }
            V[N][N-1] = N;
        } else {
            V[N].resize(N);
            V[N][0] = 2;
            for (int j = 0; j < N-1; j++) {
                V[N][j+1] = 2 * V[N-1][j];
            }
        }
    }

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        if (N == 2) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
            for (int v : V[N]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
}
