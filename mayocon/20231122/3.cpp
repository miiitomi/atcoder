// https://atcoder.jp/contests/abc264/tasks/abc264_c
#include <bits/stdc++.h>
using namespace std;

int H1, W1, H2, W2;
vector<vector<int>> A, B;

bool is_ok(vector<int> &v, vector<int> &w) {
    vector<vector<int>> C, D;
    for (int i = 0; i < H1; i++) {
        if (v[i] == 1) C.push_back(A[i]);
    }
    D.resize(H2);
    for (int j = 0; j < W1; j++) {
        if (w[j] == 1) {
            for (int i = 0; i < H2; i++) {
                D[i].push_back(C[i][j]);
            }
        }
    }

    return D == B;
}

int main() {
    cin >> H1 >> W1;
    A.assign(H1, vector<int>(W1, 0));
    for (int i = 0; i < H1; i++) {
        for (int j = 0; j < W1; j++) {
            cin >> A[i][j];
        }
    }
    cin >> H2 >> W2;
    B.assign(H2, vector<int>(W2, 0));
    for (int i = 0; i < H2; i++) {
        for (int j = 0; j < W2; j++) {
            cin >> B[i][j];
        }
    }

    vector<int> v(H1, 0), w(W1, 0);
    for (int i = 0; i < H2; i++) v[H1-1-i] = 1;
    for (int i = 0; i < W2; i++) w[W1-1-i] = 1;

    do {
        do {
            if (is_ok(v, w)) {
                cout << "Yes" << endl;
                return 0;
            }
        } while (next_permutation(w.begin(), w.end()));
    } while (next_permutation(v.begin(), v.end()));

    cout << "No" << endl;
}
