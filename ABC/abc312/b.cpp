#include <bits/stdc++.h>
using namespace std;

bool is_tak_code(int N, int M, vector<string> &S, int i, int j) {
    for (int k = 0; k < 4; k++) {
        for (int l = 0; l < 4; l++) {
            if (k < 3 && l < 3) {
                if (S[i+k][j+l] != '#') return false;
                if (S[i+8-k][j+8-l] != '#') return false;
            } else {
                if (S[i+k][j+l] != '.') return false;
                if (S[i+8-k][j+8-l] != '.') return false;
            }
        }
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    for (int i = 0; i + 8 < N; i++) {
        for (int j = 0; j + 8 < M; j++) {
            if (is_tak_code(N, M, S, i, j)) {
                cout << i+1 << " " << j+1 << endl;
            }
        }
    }
}
