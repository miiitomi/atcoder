#include <bits/stdc++.h>
using namespace std;

void solve() {
    int M, N;
    cin >> M >> N;
    vector<string> V(M);
    for (int i = 0; i < M; i++) cin >> V[i];

    int num_blacks = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (V[i][j] == 'U') {
                if (num_blacks > 0) {
                    V[i][j] = 'W';
                    V[i+1][j] = 'B';
                    num_blacks--;
                } else {
                    V[i][j] = 'B';
                    V[i+1][j] = 'W';
                    num_blacks++;
                }
            }
        }
        if (num_blacks != 0) {
            cout << -1 << endl;
            return;
        }
    }

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < M; i++) {
            if (V[i][j] == 'L') {
                if (num_blacks > 0) {
                    V[i][j] = 'W';
                    V[i][j+1] = 'B';
                    num_blacks--;
                } else {
                    V[i][j] = 'B';
                    V[i][j+1] = 'W';
                    num_blacks++;
                }
            }
        }
        if (num_blacks != 0) {
            cout << -1 << endl;
            return;
        }
    }

    for (string s : V) cout << s << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
