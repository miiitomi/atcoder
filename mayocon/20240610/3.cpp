// https://atcoder.jp/contests/abc258/tasks/abc258_b
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> dx{1,-1, 0, 0, 1, -1, 1, -1};
vector<int> dy{0, 0, 1, -1, 1, 1, -1, -1};

void solve() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) A[i][j] = s[j] - '0';
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        for (int k = 0; k < 8; k++) {
            int x = i, y = j;
            ll tmp = A[i][j];
            for (int l = 0; l < N-1; l++) {
                x = (x + dx[k] + N) % N;
                y = (y + dy[k] + N) % N;
                tmp = (tmp * 10) + A[x][y];
            }
            ans = max(ans, tmp);
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
