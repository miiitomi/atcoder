// https://atcoder.jp/contests/abc121/tasks/abc121_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, C;
    cin >> N >> M >> C;
    vector<int> B(M);
    for (int i = 0; i < M; i++) cin >> B[i];

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int tmp = C;
        for (int j = 0; j < M; j++) {
            int b;
            cin >> b;
            tmp += b * B[j];
        }
        if (tmp > 0) ans++;
    }
    cout << ans << endl;
}
