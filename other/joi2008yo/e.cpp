#include <bits/stdc++.h>
using namespace std;

int f(int R, int C, vector<vector<bool>> a, int b) {
    for (int i = 0; i < R; i++) {
        if ((1 << i) & b) {
            for (int j = 0; j < C; j++) {
                a[i][j] = !a[i][j];
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < C; j++) {
        int counter = 0;
        for (int i = 0; i < R; i++) counter += a[i][j];
        ans += max(counter, R-counter);
    }

    return ans;
}

int main() {
    int R, C;
    cin >> R >> C;
    vector<vector<bool>> a(R, vector<bool>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int x;
            cin >> x;
            a[i][j] = (x == 1);
        }
    }

    int ans = 0;
    for (int b = 0; b < (1 << R); b++) {
        ans = max(ans, f(R, C, a, b));
    }
    cout << ans << endl;
}
