#include <bits/stdc++.h>
using namespace std;

bool is_ok(int N, vector<int> &v, vector<vector<bool>> &B) {
    for (int i = 0; i < N-1; i++) {
        int x = v[i], y = v[i+1];
        if (B[x][y]) return false;
    }
    return true;
}

int compute_time(int N, vector<int> &v, vector<vector<int>> &A) {
    int ans = 0;
    for (int j = 0; j < N; j++) {
        int i = v[j];
        ans += A[i][j];
    }
    return ans;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> A[i][j];
    }

    vector<vector<bool>> B(N, vector<bool>(N, false));
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        B[x][y] = true;
        B[y][x] = true;
    }

    int ans = 2e+9;
    vector<int> v(N);
    for (int i = 0; i < N; i++) v[i] = i;

    do {
        if (!is_ok(N, v, B)) continue;
        ans = min(ans, compute_time(N, v, A));
    } while (next_permutation(v.begin(), v.end()));

    if (ans == 2e+9) cout << -1 << endl;
    else cout << ans << endl;
}
