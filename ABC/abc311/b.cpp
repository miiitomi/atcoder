#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, D;
    cin >> N >> D;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    int ans = 0;
    int now = 0;

    for (int d = 0; d < D; d++) {
        bool is_free = true;
        for (int i = 0; i < N; i++) {
            if (S[i][d] == 'x') {
                is_free = false;
                break;
            }
        }

        if (!is_free) {
            ans = max(ans, now);
            now = 0;
        } else {
            now++;
        }
    }
    ans = max(ans, now);

    cout << ans << endl;
}
