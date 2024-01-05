// https://atcoder.jp/contests/abc050/tasks/abc050_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> T(N);
    for (int i = 0; i < N; i++) cin >> T[i];

    int M;
    cin >> M;
    vector<int> P(M), X(M);
    for (int i = 0; i < M; i++) {
        cin >> P[i] >> X[i];
        P[i]--;
    }

    for (int i = 0; i < M; i++) {
        int p = P[i], x = X[i], ans = 0;
        for (int j = 0; j < N; j++) {
            if (p == j) ans += x;
            else ans += T[j];
        }
        cout << ans << endl;
    }
}
