#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<vector<int>> A, B;

int f(vector<int> &v) {
    int N = v.size();
    vector<int> w(N);
    for (int i = 0; i < N; i++) w[i] = i;
    int cnt = 0;
    for (int k = 0; k < N; k++) {
        if (v[k] == w[k]) continue;
        int i = -1;
        for (int j = k+1; j < N; j++) if (w[j] == v[k]) {
            i = j;
            continue;
        }
        while (i > k) {
            swap(w[i], w[i-1]);
            cnt++;
            i--;
        }
    }
    return cnt;
}

bool is_ok(vector<int> &v, vector<int> &w) {
    vector<vector<int>> C(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            C[i][j] = A[v[i]][w[j]];
        }
    }
    return B == C;
}

int main() {
    cin >> H >> W;
    A.assign(H, vector<int>(W, 0));
    B.assign(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> B[i][j];
        }
    }

    vector<int> v(H);
    for (int i = 0; i < H; i++) v[i] = i;
    int ans = 1e+9;

    do {
        int tmp = f(v);
        vector<int> w(W);
        for (int i = 0; i < W; i++) w[i] = i;
        do {
            if (is_ok(v, w)) {
                ans = min(ans, tmp + f(w));
            }
        } while (next_permutation(w.begin(), w.end()));
    } while (next_permutation(v.begin(), v.end()));

    if (ans == (int)1e+9) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
