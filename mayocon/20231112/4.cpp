// https://atcoder.jp/contests/abc128/tasks/abc128_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> k(M);
    vector<vector<int>> s(M);
    for (int i = 0; i < M; i++) {
        cin >> k[i];
        s[i].resize(k[i]);
        for (int j = 0; j < k[i]; j++) {
            cin >> s[i][j];
            s[i][j]--;
        }
    }
    vector<int> p(M);
    for (int i = 0; i < M; i++) cin >> p[i];

    int ans = 0;
    for (int x = 0; x < (1 << N); x++) {
        bool ok = true;
        for (int i = 0; i < M; i++) {
            int cnt = 0;
            for (int a : s[i]) {
                if (x & (1 << a)) cnt++;
            }
            if (cnt % 2 != p[i]) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    }

    cout << ans << endl;
}
