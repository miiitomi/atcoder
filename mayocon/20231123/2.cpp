// https://atcoder.jp/contests/abc312/tasks/abc312_b
#include <bits/stdc++.h>
using namespace std;

vector<string> T{
    "###.*****",
    "###.*****",
    "###.*****",
    "....*****",
    "*********",
    "*****....",
    "*****.###",
    "*****.###",
    "*****.###"
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i + 8 >= N || j + 8 >= M) continue;
            bool ok = true;
            for (int s = 0; s < 9; s++) {
                for (int t = 0; t < 9; t++) {
                    if ((S[i+s][j+t] != T[s][t]) && (T[s][t] != '*')) ok = false;
                }
            }
            if (ok) {
                cout << i+1 << " " << j+1 << endl;
            }
        }
    }
}
