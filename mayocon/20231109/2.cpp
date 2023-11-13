// https://atcoder.jp/contests/abc225/tasks/abc225_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> B(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> B[i][j];
        }
    }

    int i, j;
    if (B[i][j] % 7 == 0) i = (B[i][j]-1) / 7, j = ((B[0][0] % 7) - 1 + 7) % 7;
    else i = B[0][0] / 7, j = ((B[0][0] % 7) - 1 + 7) % 7;

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (B[x][y] != (i + x) * 7 + j + y + 1 || j + y + 1 > 7) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
}
