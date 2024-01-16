// https://atcoder.jp/contests/abc258/tasks/abc258_b
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) A[i][j] = s[j] - '0';
    }
    ll ans = -1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;
                    ll tmp = 0;
                    int x = i, y = j;
                    for (int k = 0; k < N; k++) {
                        tmp = tmp*10 + A[x][y];
                        x = (x + dx + N) % N;
                        y = (y + dy + N) % N;
                    }
                    ans = max(ans, tmp);
                }
            }
        }
    }

    cout << ans << endl;
}
