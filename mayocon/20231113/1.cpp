// https://atcoder.jp/contests/abc272/tasks/abc272_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> ok(N, vector<bool>(N, false));
    for (int i = 0; i < M; i++) {
        int K;
        cin >> K;
        vector<int> v(K);
        for (int j = 0; j < K; j++) {
            cin >> v[j];
            v[j]--;
        }
        for (int x = 0; x < K; x++) {
            for (int y = 0; y < K; y++) {
                ok[v[x]][v[y]] = true;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!ok[i][j]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
