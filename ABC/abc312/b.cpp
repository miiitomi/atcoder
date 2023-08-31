#include <bits/stdc++.h>
using namespace std;

bool is_tak(int x, int y, vector<string> &S) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i < 3 && j < 3) {
                if (S[x+i][y+j] != '#' || S[x+8-i][y+8-j] != '#') {
                    return false;
                }
            } else {                
                if (S[x+i][y+j] != '.' || S[x+8-i][y+8-j] != '.') {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int M, N;
    cin >> M >> N;
    vector<string> S(M);
    for (int i = 0; i < M; i++) {
        cin >> S[i];
    }

    for (int i = 0; i+8 < M; i++) {
        for (int j = 0; j+8 < N; j++) {
            if (is_tak(i, j, S)) cout << i+1 << " " << j+1 << endl;
        }
    }
}
