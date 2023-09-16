#include <bits/stdc++.h>
using namespace std;

int main() {
    int M;
    cin >> M;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int ans = (int)1e+9;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < M; k++) {
                if (s1[i] == s2[j] && s2[j] == s3[k]) {
                    if (i != j && j != k && k != i) {
                        ans = min(ans, max(i, max(j, k)));
                    } else if (i == j && j == k) {
                        ans = min(ans, i + 2*M);
                    } else if (i == j) {
                        ans = min(ans, i + M);
                    } else if (j == k) {
                        ans = min(ans, j + M);
                    } else {
                        ans = min(ans, i+ M);
                    }
                }
            }
        }
    }

    if (ans == (int)1e+9) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
