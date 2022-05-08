#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    vector<vector<bool>> C(N, vector<bool>(N, false));
    vector<vector<char>> S(A*N, vector<char>(B*N, '.'));

    bool color = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j == 0 && i != 0) {
                color = !C[i-1][0];
            }
            C[i][j] = color;

            if (color) {
                for (int a = i*A; a < (i+1)*A; a++) {
                    for (int b = j*B; b < (j+1)*B; b++) {
                        S[a][b] = '#';
                    }
                }
            }
            color = !color;
        }
    }

    for (int i = 0; i < A*N; i++) {
        for (int j = 0; j < B*N; j++) {
            cout << S[i][j];
        }
        cout << endl;
    }
}
