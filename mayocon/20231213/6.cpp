// https://atcoder.jp/contests/abc271/tasks/abc271_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    vector<map<int, ll>> cnt(N);
    for (int s = 0; s < (1 << (N-1)); s++) {
        int i = 0, j = 0, x = A[i][j];
        for (int k = 0; k < N-1; k++) {
            if (s & (1 << k)) i++;
            else j++;
            x ^= A[i][j];
        }
        cnt[i][x]++;
    }

    ll ans = 0;
    for (int s = 0; s < (1 << (N-1)); s++) {
        int i = N-1, j = N-1, x = 0;
        for (int k = 0; k < (N-1); k++) {
            x ^= A[i][j];
            if (s & (1 << k)) i--;
            else j--;
        }
        ans += cnt[i][x];
    }

    cout << ans << endl;
}
