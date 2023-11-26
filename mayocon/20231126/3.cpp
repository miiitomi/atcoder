// https://atcoder.jp/contests/abc057/tasks/abc057_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> a(N), b(N), c(M), d(M);
    for (int i = 0; i < N; i++) cin >> a[i] >> b[i];
    for (int i = 0; i < M; i++) cin >> c[i] >> d[i];

    for (int i = 0; i < N; i++) {
        int x = a[i], y = b[i];
        int tmp = 2e+9, tmp_i = -1;
        for (int j = 0; j < M; j++) {
            if (tmp > abs(x - c[j]) + abs(y - d[j])) {
                tmp = abs(x - c[j]) + abs(y - d[j]);
                tmp_i = j;
            }
        }
        cout << tmp_i + 1 << endl;
    }
}
