// https://atcoder.jp/contests/abc256/tasks/abc256_c
#include <bits/stdc++.h>
using namespace std;

vector<int> h(3), w(3);

bool ok(vector<vector<int>> &a) {
    bool done = false;
    while (!done) {
        done = true;
        for (int i = 0; i < 3; i++) {
            int cnt = 0, sum = 0, nj;
            for (int j = 0; j < 3; j++) {
                cnt += (a[i][j] == 0);
                sum += a[i][j];
                if (a[i][j] == 0) nj = j;
            }
            if (cnt == 1) {
                if (sum >= h[i]) {
                    return false;
                } else {
                    a[i][nj] = h[i] - sum;
                    done = false;
                }
            }
        }
        for (int j = 0; j < 3; j++) {
            int cnt = 0, sum = 0, ni;
            for (int i = 0; i < 3; i++) {
                cnt += (a[i][j] == 0);
                sum += a[i][j];
                if (a[i][j] == 0) ni = i;
            }
            if (cnt == 1) {
                if (sum >= w[j]) {
                    return false;
                } else {
                    a[ni][j] = w[j] - sum;
                    done = false;
                }
            }
        }
    }
    
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) sum += a[i][j];
        if (sum != h[i]) return false;
    }
    for (int j = 0; j < 3; j++) {
        int sum = 0;
        for (int i = 0; i < 3; i++) sum += a[i][j];
        if (sum != w[j]) return false;
    }

    return true;
}

int main() {
    for (int i = 0; i < 3; i++) cin >> h[i];
    for (int j = 0; j < 3; j++) cin >> w[j];

    int ans = 0;
    for (int x = 1; x <= 28; x++) {
        for (int y = 1; y <= 28; y++) {
            for (int z = 1; z <= 28; z++) {
                for (int s = 1; s <= 28; s++) {
                    vector<vector<int>> a(3, vector<int>(3, 0));
                    a[0][0] = x;
                    a[1][1] = y;
                    a[2][2] = z;
                    a[0][1] = s;
                    if (ok(a)) ans++;
                }
            }
        }
    }
    cout << ans << endl;
}
